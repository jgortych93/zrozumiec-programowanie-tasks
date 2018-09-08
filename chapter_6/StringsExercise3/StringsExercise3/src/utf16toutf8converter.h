#ifndef UTF16TOUTF8CONVERTER_H
#define UTF16TOUTF8CONVERTER_H

#include <string>
#include <vector>
using namespace std;

class UTF16ToUTF8Converter
{
    u16string inputString;

public:
    UTF16ToUTF8Converter();
    u16string convertToUTF8(const u16string &utf16String);

private:
    vector<char16_t> decodeUTF16() const;
    void decodeMaskedSign(vector<char16_t>& codes, int iterator) const;
};

#endif // UTF16TOUTF8CONVERTER_H
