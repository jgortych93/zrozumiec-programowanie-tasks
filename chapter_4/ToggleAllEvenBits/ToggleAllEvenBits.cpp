/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <math.h>

#define BITS_NUMBER 8

using namespace std;

template<typename T> void toggleAllEvenBits( T& number )
{
    size_t sizeOfNumber = sizeof( number );
    cout<<sizeOfNumber;
    
    T mask = 0U;
    T maxSettingBit = pow( 2, (sizeOfNumber*BITS_NUMBER-1) );

    // Setting the mask dynamicaly based on param type
    // Alternatively since C++ 14 (or using GCC compiler) is is possible to set mask using binary literal (int32 example: uint32t mask = 0b10101010101010101010101010101010 )
    // Or using dec represantion: 2863311530U
    for ( T settingBit = 2U; settingBit <= maxSettingBit; settingBit <<= 2 )
    {
        mask |= settingBit;
        cout<<settingBit;
        
        // We need to break here, otherway the number will be 0
        if ( settingBit == maxSettingBit)
            break;
    }
    
    number ^= mask;
}

int main()
{
    unsigned char i = 10;
    
    toggleAllEvenBits( i );
    
    cout<<"result: "<<i;

    return 0;
}
