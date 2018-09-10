#include "utf16toutf8converter.h"
#include <iostream>
#define FIRST_RANGE_START   0x0000u
#define FIRST_RANGE_END     0xD7FFu
#define SECOND_RANGE_START  0xE000u
#define SECOND_RANGE_END    0xFFFFu
#define DOWN_TEN_BITS_MASK  0x3FFFFu

#define SECOND_16_BIT_NUMBER_DOWN_RANGE     0xDC00u
#define SECOND_16_BIT_NUMBER_UPPER_RANGE    0xDFFFu

#define TEN 10u
#define UTF16_UPPER_RANGE   0x10000u

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

    string result = encodeToUTF8(decodedSigns);

    return  result;
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

string UTF16ToUTF8Converter::encodeToUTF8(const vector<uint32_t> &codes) const
{

}
