#include <stdio.h>

unsigned char turnOffLastSetBit(unsigned char number)
{
    unsigned char checkValue = 1;
    unsigned char tempValue = 0;
    unsigned char result = 0;

    for (int i=0; i<=8; ++i)
    {

        tempValue = number & checkValue;
        if (tempValue)
        {
            result = number & (~checkValue);
            break;
        }

        checkValue <<= 1;

    }
    return result;

}

int main()
{
    unsigned char number;
    printf("Give your number (from 0 to 255)\n");
    scanf("%hhu", &number);

    printf("The result is: %hhu: ", turnOffLastSetBit(number));


    return 0;
}
