#include "factorial.h"

Factorial::Factorial()
{

}

uint32_t Factorial::getFactorialByIteration(uint32_t number) const
{
    if (0u == number)
        return number;
    else if (1u == number)
        return number;

    uint32_t result = number--;
    for (; number>0;--number)
    {
        result *= number;
    }

    return result;
}

uint32_t Factorial::getFactorialByRecurrency(uint32_t number) const
{
    if (number <= 1u)
        return number;

    uint32_t result = number;
    return result *= getFactorialByRecurrency(--number);
}
