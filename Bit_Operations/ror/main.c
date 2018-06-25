#include <stdio.h>
#define FIRST_BIT 128

unsigned char rotate_right(unsigned char number)
{
    unsigned char result = number;

    unsigned char lastBit = result & 1;

    result >>= 1;

    if (lastBit)
        result |= FIRST_BIT;

    return result;

}

unsigned char rotate_left(unsigned char number)
{
    unsigned char result = number;

    unsigned char firstBit = result & FIRST_BIT;

    result <<= 1;

    if (firstBit)
        result |= firstBit;

    return result;

}

int main()
{
    unsigned char number;
    printf("Give your number (from 0 to 255\n");
    scanf("%hhu", &number);


    printf("Right rotated number is: %hhu\n", rotate_right(number));
    printf("left rotated number is: %hhu\n", rotate_left(number));


    return 0;
}
