#ifndef UTF16TOUTF8CONVERTER_H
#define UTF16TOUTF8CONVERTER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class UTF16ToUTF8Converter
{
    u16string inputString;

public:
    UTF16ToUTF8Converter();
    ~UTF16ToUTF8Converter(){delete bytesRangesInUTF8;}
    string convertToUTF8(const u16string &utf16String);

private:
    vector<uint32_t> decodeUTF16() const;
    void decodeMaskedSign(vector<uint32_t>& codes, uint32_t iterator) const;
    vector<uint8_t> encodeToUTF8(vector<uint32_t> codes) const;
    uint32_t countBits(const uint32_t& number) const;
    uint8_t getNeededNumberOfBytes(const uint32_t numberOfBits) const;

    const static map<uint8_t, uint8_t>* bytesRangesInUTF8;
};

#endif // UTF16TOUTF8CONVERTER_H
