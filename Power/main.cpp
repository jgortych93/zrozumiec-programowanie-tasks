#include <iostream>
#include "powers.h"

using namespace std;

int main()
{
    double number = 0.0;
    int exponent = 0;

    while(true)
    {
        cout<<"Give number: "<<endl;
        cin>>number;
        cout<<"Give exponent: "<<endl;
        cin>>exponent;

        Power power;

        cout<<"Power iterational: "<<power.getPowerIterational(number, exponent)<<endl;
        cout<<"Power recursive: "<<power.getPowerRecursive(number, exponent)<<endl;

    }

    return 0;
}
