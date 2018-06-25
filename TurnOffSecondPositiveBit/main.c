#include <stdio.h>

unsigned char turnOffSecondLastSetBit(unsigned char number)
{
    unsigned char result = 0;



    return result;
}


int main()
{
    unsigned char number;
    printf("Give your number (from 0 to 255)\n");
    scanf("%hhu", &number);

    printf("The result is: %hhu: ", turnOffSecondLastSetBit(number));
    return 0;
}
