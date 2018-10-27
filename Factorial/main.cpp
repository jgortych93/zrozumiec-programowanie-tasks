#include <iostream>
#include <factorial.h>

using namespace std;

int main()
{
    Factorial factorial;
    uint32_t number;

    while(true)
    {
    cout<<"Give number: "<<endl;
    cin>>number;

    cout<<"Factorial by iteration: "<<factorial.getFactorialByIteration(number)<<endl;
    cout<<"Factorial by recurrency: "<<factorial.getFactorialByRecurrency(number)<<endl;

    }

    return 0;
}
