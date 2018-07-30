#include <stdio.h>

#define NUMBER_OF_BYTES 4
#define NUMBER_OF_BITS  8
#define NUMBER_OF_BITS_IN_TOTAL 32

void printInteger(unsigned int number)
{
    printf("The number in big endian is: \n");

    unsigned int checkingBit = 2147483648;

    for (int i=0; i < 32; ++i){

        if ((number & checkingBit) != 0)
            printf("1");
        else
            printf("0");

        checkingBit >>= 1;

        if ((i+1) % 8 == 0)
            printf(" ");

    }

    printf("\n");

}

void printIntegerInLittleEndian(unsigned int number)
{
    printf("The number in little endian is: \n");

    unsigned int checkingBit = 2147483648;
    unsigned char littleEndianRepresentation[NUMBER_OF_BYTES][NUMBER_OF_BITS];
    unsigned int currentByte = 0;
    unsigned int currentBit = 0;

    for (int i=0; i < NUMBER_OF_BITS_IN_TOTAL; ++i){

        if ((number & checkingBit) != 0)
            littleEndianRepresentation[currentByte][currentBit] = 1;
        else
            littleEndianRepresentation[currentByte][currentBit] = 0;

        checkingBit >>= 1;
        ++currentBit;

        if ((i+1) % 8 == 0){
            ++currentByte;
            currentBit = 0;
        }

    }

    for (int i = NUMBER_OF_BYTES-1; i >= 0; --i){
        for (int j=0; j < NUMBER_OF_BITS; ++j){
            printf("%hhu", littleEndianRepresentation[i][j]);
        }
        printf(" ");
    }

    printf("\n");

}


int main()
{
    unsigned int number;

    while(1){

        printf("Give your number (from 0 to 4,294,967,295)\n");
        scanf("%d", &number);

        printInteger(number);
        printIntegerInLittleEndian(number);
    }

    return 0;
}
