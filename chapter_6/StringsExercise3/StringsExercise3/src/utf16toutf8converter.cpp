#include "utf16toutf8converter.h"
#include <iostream>
#include <math.h>
#include <algorithm>

#define FIRST_RANGE_START   0x0000u
#define FIRST_RANGE_END     0xD7FFu
#define SECOND_RANGE_START  0xE000u
#define SECOND_RANGE_END    0xFFFFu
#define DOWN_TEN_BITS_MASK  0x3FFFFu

#define TEN 10u
#define UTF16_UPPER_RANGE   0x10000u

#define ASCII_UPPER_RANGE   0x7fu
#define SIX_LAST_BITS_MASK  0x3fu

const map<uint8_t,uint8_t>* UTF16ToUTF8Converter::bytesRangesInUTF8 = new map<uint8_t, uint8_t>{
    {7,1}, {11,2},{16,3},{21,4}
};

UTF16ToUTF8Converter::UTF16ToUTF8Converter()
{

}

string UTF16ToUTF8Converter::convertToUTF8(const u16string& utf16String)
{
    this->inputString = utf16String;

    vector<uint32_t> decodedSigns = decodeUTF16();

    for (int i = 0; i < decodedSigns.size(); ++i)
    {
        cout<<decodedSigns[i]<<endl;
    }

    vector<uint8_t> result = encodeToUTF8(decodedSigns);

    return  string(result.begin(), result.end());
}

vector<uint32_t> UTF16ToUTF8Converter::decodeUTF16() const
{
    vector<uint32_t> codes;

    for(uint32_t i=0; i < this->inputString.length(); ++i)
    {
        if( (this->inputString[i] >= FIRST_RANGE_START  && this->inputString[i] <= FIRST_RANGE_END) ||
                (this->inputString[i] >= SECOND_RANGE_START && this->inputString[i] <= SECOND_RANGE_END) )
        {
            codes.push_back(static_cast<uint32_t>(this->inputString[i]));
        }
        else
        {
            decodeMaskedSign(codes, i);
            codes[++i] = 0u;
        }
    }

    return codes;
}

void UTF16ToUTF8Converter::decodeMaskedSign(vector<uint32_t> &codes, uint32_t iterator) const
{
    uint32_t firstSign = static_cast<uint32_t>(this->inputString[iterator]) & DOWN_TEN_BITS_MASK;
    uint32_t secondSign = static_cast<uint32_t>(this->inputString[iterator+1u]) & DOWN_TEN_BITS_MASK;

    uint32_t combinedSign = 0u;
    combinedSign |= (firstSign << TEN);
    combinedSign |= secondSign;

    combinedSign += UTF16_UPPER_RANGE;

    codes[iterator] = combinedSign;

}

vector<uint8_t> UTF16ToUTF8Converter::encodeToUTF8(vector<uint32_t> codes) const
{
    vector<uint8_t> result;

    vector<uint32_t>::iterator it;

    for (it = codes.begin(); it < codes.end(); ++it)
    {
        if (*it <=  ASCII_UPPER_RANGE)
            result.push_back(static_cast<uint8_t>(*it));
        else
        {
            /*
             * Rest of algorithm:
             * - check the number of bits in sign code
             * - create the Map to map ranges of bit sizes to number of bytes needed for encoding the sign in UTF8
             * - first byte has as many ones as the needed number of bytes
             * - rest of bytes start from 10 and then use the other 6 bits to store data
             */

            uint32_t numberOfBits = this->countBits(*it);
            const uint8_t numberOfBytes = this->getNeededNumberOfBytes(numberOfBits);

            vector<uint8_t> temporaryVector;
            for (int i = 0; i < numberOfBytes; ++i)
            {
                temporaryVector.push_back((2 << 6) | (*it & SIX_LAST_BITS_MASK));
                (*it) >>= 6;
            }

            //First byte
            temporaryVector.push_back(static_cast<uint8_t>(((0xFFu << (8u - static_cast<uint32_t>(numberOfBytes))) & (0xFFu | static_cast<uint32_t>((*it))))));
            reverse(temporaryVector.begin(), temporaryVector.end());

            result.insert(result.end(), temporaryVector.begin(), temporaryVector.end());

        }
    }

    return  result;
}

uint32_t UTF16ToUTF8Converter::countBits(const uint32_t &number) const
{

    // log function in base 2
    // take only integer part
    return static_cast<uint32_t>(log2(number))+1u;

}

uint8_t UTF16ToUTF8Converter::getNeededNumberOfBytes(const uint32_t numberOfBits) const
{
    map<uint8_t,uint8_t>::const_iterator mapIterator;

    for (mapIterator = bytesRangesInUTF8->begin();mapIterator != bytesRangesInUTF8->end(); ++mapIterator)
    {
        if (static_cast<const uint32_t>(mapIterator->first) >= numberOfBits)
            return mapIterator->second;
    }

    return 0;
}
