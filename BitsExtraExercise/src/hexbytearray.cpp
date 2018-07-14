#include "hexbytearray.h"
#include <sstream>

#define MAX_LENGTH    2

HexByteArray::HexByteArray(const string &fileToParseName)
{
    this->fileName = fileToParseName;
}

void HexByteArray::appendNumbersToArray()
{
    char* text = this->saveTextToBuffer();
    if (text == nullptr){
        return;
    }

    unsigned int i = 0;
    string tempString;
    unsigned char number;
    //stringstream stringStream;

    while(text[i])
    {
        if ((isdigit(text[i])) || (text[i] >= 'A' && text[i] <= 'F')) // ASCII representation range
        {
            tempString += text[i];

            if (tempString.length() == MAX_LENGTH)
            {
                // stringstream usage (before C++11): hex, dec, oct means read number as
                //stringStream << std::hex << tempString;
                //stringStream >> number;
                number = static_cast<unsigned char>(strtoul(tempString.c_str(), nullptr, 16));  // base is 0 in case of '0x'
                tempString.clear();

                byteArray.push_back(number);
            }
        }
        ++i;
    }

    delete[] text;
}


char* HexByteArray::saveTextToBuffer()
{
    ifstream file(this->fileName);
    if(file){

        file.seekg(0, file.end);    //move the curr pos to end, read position and move it back
        long length = file.tellg();
        file.seekg(0, file.beg);

        char* buffer = new char[length];

        try {

            file.read(buffer, length);  // read 'length' number of bytes to char array

            file.close();

        } catch (exception ex) {
            cout<<ex.what()<<endl;
            delete[] buffer;
            return nullptr;
        }
        return buffer;

    }
    return nullptr;
}
