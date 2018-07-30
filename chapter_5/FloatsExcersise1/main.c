#include <stdio.h>
#include <stdlib.h>



void convertBinaryFractalsWithArray(char* fractals)
{
    static double negativeTwoPowers[10];
    negativeTwoPowers[0] = (1.0/2.0);
    negativeTwoPowers[1] = (1.0/4.0);
    negativeTwoPowers[2] = (1.0/8.0);
    negativeTwoPowers[3] = (1.0/16.0);
    negativeTwoPowers[4] = (1.0/32.0);
    negativeTwoPowers[5] = (1.0/64.0);
    negativeTwoPowers[6] = (1.0/128.0);
    negativeTwoPowers[7] = (1.0/256.0);
    negativeTwoPowers[8] = (1.0/512.0);
    negativeTwoPowers[9] = (1.0/1024.0);

    double result = 0;
    for (int i = 0; i < 8; ++i)
    {
        result += (double)fractals[i] * negativeTwoPowers[i];
    }

    printf("Result is: %f\n", result);
}


int main()
{
    char firstNumber[8] = {1,0,0,0,0,0,0,0};
    char secondNumber[8] = {0,1,0,0,0,0,0,0};
    char thirdNumber[8] = {1,1,0,0,0,0,0,0};
    char fourthNumber[8] = {1,0,1,1,0,1,1,0};

    convertBinaryFractalsWithArray(firstNumber);
    convertBinaryFractalsWithArray(secondNumber);
    convertBinaryFractalsWithArray(thirdNumber);
    convertBinaryFractalsWithArray(fourthNumber);

    return 0;
}
