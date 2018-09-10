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
    string convertToUTF8(const u16string &utf16String);

private:
    vector<uint32_t> decodeUTF16() const;
    void decodeMaskedSign(vector<uint32_t>& codes, uint32_t iterator) const;
    string encodeToUTF8(const vector<uint32_t>& codes) const;
};

#endif // UTF16TOUTF8CONVERTER_H
