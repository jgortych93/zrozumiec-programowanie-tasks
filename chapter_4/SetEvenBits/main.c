#include <stdio.h>
#define EVEN_BITS_MASK 212
#define FIRST_EVEN_BIT 4

unsigned char setEvenBitsInByteWithMask(unsigned char number)
{
    unsigned char resut = number & 0;
    return resut | EVEN_BITS_MASK;
}

/*unsigned char setEvenBitsWithoutMask(unsigned char number)
{
    unsigned char firstEvenBit = 4;
    unsigned char result = 0;

    for (int i = 0; i < 4; ++i)
    {
        result
    }
}*/

int main()
{
    unsigned char number;
    printf("Give your number (from 0 to 255)\n");
    scanf("%hhu", &number);

    printf("Even bits set by mask gives vale: %d", setEvenBitsInByteWithMask(number));


    return 0;
}
