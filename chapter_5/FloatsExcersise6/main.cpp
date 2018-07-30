#include <iostream>
#include "myfixed1616.h"

using namespace std;

int main()
{
    double x;

    do {
    cout<<"Please provide positive x"<<endl;
    cin>>x;
    }
    while (x < 0);

    fixed_16_16_t fixed_x = double_to_fixed_16_16(x);

    double double_result = getSinus(x);
    double fixed_result = fixed_16_16_to_double(getSinus(fixed_x));

    /*cout<<"Double Taylor function result: "<<double_result<<endl;
    cout<<"Fixed type Taylor function result: "<<fixed_result<<endl;
    cout<<"Relative error: " << (double_result - fixed_result) / double_result<<endl;*/

    printf("taylor function with fixed_16_16_t = %.50f\n", fixed_result);
        printf("taylor function with double = %.50f\n", double_result);
        printf("realitive error = %.50f\n", ((double_result - fixed_result) / double_result ));

    return 0;
}
