#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    unsigned char bytes[4] = {72,255,9,67};
    float number;

    memcpy(&number, bytes, 4);

    cout<<number;

    return 0;
}
