#include <iostream>
#include "hexbytearray.h"

#define FILE_PATH "../BitsExtraExercise/Input/Input"

using namespace std;

int main()
{

    HexByteArray programArray(FILE_PATH);

    programArray.appendNumbersToArray();
    programArray.divideArrayBasedOnBitsParity();

    programArray.printByteVectors();

    return 0;
}
