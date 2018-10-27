#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <stdint.h>


class Factorial
{
public:
    Factorial();

    uint32_t getFactorialByIteration(uint32_t number) const;
    uint32_t getFactorialByRecurrency(uint32_t number) const;
};

#endif // FACTORIAL_H
