#ifndef MYFIXED1616_H
#define MYFIXED1616_H

#include<cstdint>
#include<stdio.h>
#include<math.h>

typedef int32_t fixed_16_16_t;

static fixed_16_16_t double_to_fixed_16_16(double double_value) {
    return (int32_t) (double_value * 65536.0);
}

static double fixed_16_16_to_double(fixed_16_16_t fixed_value) {
    return (double) fixed_value / 65536.0;
}

static fixed_16_16_t add(fixed_16_16_t a, fixed_16_16_t b) {
    return (double) a + b;
}

static fixed_16_16_t substract(fixed_16_16_t a, fixed_16_16_t b) {
    return (double) a - b;
}

static fixed_16_16_t multiply(fixed_16_16_t a, fixed_16_16_t b) {
    return ((int64_t) a * (int64_t) b) >> 16;
}

static fixed_16_16_t divide(fixed_16_16_t a, fixed_16_16_t b) {
    return ((int64_t) a << 16) / b;
}

static fixed_16_16_t getPower(fixed_16_16_t base, int power) {

    /*if (power == 1)
        return base;
    else if(power == 0)
        return 1;
    else
        return base * getPower(base, --power);*/

    //Optimized alg

    if (power == 1)
        return base;
    else if (power != 0)
    {
        if (power % 2 == 0)
        {
            return (getPower(base, power/2)) * (getPower(base,power/2));
        }
        else
        {
            return base * (getPower(base, power/2)) * (getPower(base,power/2));
        }
    }
    else
    {
        return 1;
    }

}

static unsigned int getFractal(unsigned int base){

    if (base>0){
        unsigned int tempBase = base - 1;
        return (base) * getFractal(tempBase);
    }
    else if (base == 0){
        return 1;
    }
    else {
        printf("Please give only positive integers");
        return 0;
    }

}

static fixed_16_16_t getSinus(fixed_16_16_t x){
    return x - (getPower(x,3) / getFractal(3u)) + (getPower(x,5) / getFractal(5u)) - (getPower(x,7) - getFractal(7u));
}

static double getSinus(double x){
    return x - (pow(x,3) / getFractal(3u)) + (pow(x,5u) / getFractal(5)) - (pow(x,7) - getFractal(7u));
}

#endif // MYFIXED1616_H
