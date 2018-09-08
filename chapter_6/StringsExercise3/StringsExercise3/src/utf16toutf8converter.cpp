#include "utf16toutf8converter.h"
#define FIRST_RANGE_START   0x0000
#define FIRST_RANGE_END     0xD7FF
#define SECOND_RANGE_START  0xE000
#define SECOND_RANGE_END    0xFFFF
#define DOWN_TEN_BITS_MASK  0x3FFFF

UTF16ToUTF8Converter::UTF16ToUTF8Converter()
{

}

u16string UTF16ToUTF8Converter::convertToUTF8(const u16string& utf16String)
{
    this->inputString = utf16String;

     vector<char16_t> decodedSigns = decodeUTF16();
}

vector<char16_t> UTF16ToUTF8Converter::decodeUTF16() const
{
    vector<char16_t> codes;

    for(int i=0; i < this->inputString.length(); ++i)
    {
        if( (this->inputString[i] >= FIRST_RANGE_START  && this->inputString[i] <= FIRST_RANGE_END) || (this->inputString[i] >= SECOND_RANGE_START && this->inputString[i] <= SECOND_RANGE_END) )
        {
            codes.push_back(this->inputString[i]);
        }
        else
        {
            decodeMaskedSign(codes, i);
            ++i;
        }
    }

    return codes;
}

void UTF16ToUTF8Converter::decodeMaskedSign(vector<char16_t> &codes, int iterator) const
{
    int firstSign = this->inputString[iterator] &= DOWN_TEN_BITS_MASK;

    ++iterator;

    int secondSign = this->inputString[iterator] &= DOWN_TEN_BITS_MASK;

    //int combinedSign = first


}
