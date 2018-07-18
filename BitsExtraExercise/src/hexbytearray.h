#ifndef HEXBYTEARRAY_H
#define HEXBYTEARRAY_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class HexByteArray
{

    vector<unsigned char> byteArray;
    vector<unsigned char> bytesWithEvenNumberOfBits;
    vector<unsigned char> bytesWithoutEvenNumberOfBits;

    string fileName;

public:
    HexByteArray(const string &fileToParseName);
    void appendNumbersToArray();
    void divideArrayBasedOnBitsParity();
    void printByteVectors();


private:
    char* saveTextToBuffer() const;
    bool isNumberOfBitsInByteEven(const unsigned char& number) const;
    void orderVectors();

};

#endif // HEXBYTEARRAY_H
