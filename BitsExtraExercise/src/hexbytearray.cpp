#include "hexbytearray.h"
#include <sstream>
#include <algorithm>    // std::sort

#define MAX_LENGTH    2
#define OUTPUT_FILE_PATH "../BitsExtraExercise/Output/Output"

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

                byteArray.push_back(+number);
            }
        }
        ++i;
    }

    delete[] text;
}

void HexByteArray::divideArrayBasedOnBitsParity()
{
    for (vector<unsigned char>::iterator it=this->byteArray.begin(); it != this->byteArray.end(); ++it){
        if (this->isNumberOfBitsInByteEven(*it)){
            //cout<<+(*it)<<endl;
            this->bytesWithEvenNumberOfBits.push_back(*it);}
        else{
            //cout<<+(*it)<<endl;
            this->bytesWithoutEvenNumberOfBits.push_back(*it);}
    }

    this->orderVectors();
}

void HexByteArray::printByteVectors()
{

    ofstream outputFile(OUTPUT_FILE_PATH);

    if (outputFile)
    {
        try {
            outputFile<<"Number with EVEN number of bits: "<<endl;
            for (vector<unsigned char>::iterator it = this->bytesWithEvenNumberOfBits.begin(); it != this->bytesWithEvenNumberOfBits.end(); ++it)
                outputFile<<+(*it)<<endl;

            outputFile<<"Number with NOT EVEN number of bits: "<<endl;
            for (vector<unsigned char>::iterator it = this->bytesWithoutEvenNumberOfBits.begin(); it != this->bytesWithoutEvenNumberOfBits.end(); ++it)
                outputFile<<+(*it)<<endl;

        } catch (exception ex) {
            cout<<ex.what()<<endl;
        }
    }
    else
        cerr<<"No output file"<<endl;

}


char* HexByteArray::saveTextToBuffer() const
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

bool HexByteArray::isNumberOfBitsInByteEven(const unsigned char &number) const
{
    unsigned char mask = 1;
    unsigned char numberOfBits = 0;

    for (int i=0; i<8; ++i)
    {
        if (number & (mask<<i))
            ++numberOfBits;
    }

    if (numberOfBits % 2)
        return false;
    else
        return true;
}

void HexByteArray::orderVectors()
{
    std::sort(this->bytesWithEvenNumberOfBits.begin(), this->bytesWithEvenNumberOfBits.end());

    std::sort(this->bytesWithoutEvenNumberOfBits.begin(), this->bytesWithoutEvenNumberOfBits.end(), greater<unsigned char>());
}
