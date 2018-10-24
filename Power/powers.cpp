#include "powers.h"
#include <math.h>

double Power::getPowerIterational(double number, int exponent) const
{
    if ( 0.0 == number)
        return 0;
    else if( 0 == exponent)
        return 1;

    double result = number;

    for (int i=0; i < abs(exponent)-1; ++i)
    {
        result *= number;
    }

    if (exponent > 0)
        return result;
    else
        return 1/result;

}

double Power::getPowerRecursive(double number, int exponent) const
{
    if ( 0.0 == number)
        return 0;
    else if( 0 == exponent)
        return 1;
    else if (exponent > 0)
        return number *= getPowerRecursive(number, exponent - 1);
    else
        return 1/(number *= getPowerRecursive(number, abs(exponent) - 1));



}
