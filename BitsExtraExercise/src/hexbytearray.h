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
    string fileName;

public:
    HexByteArray(const string &fileToParseName);
    void appendNumbersToArray();


private:
    char* saveTextToBuffer();

};

#endif // HEXBYTEARRAY_H
