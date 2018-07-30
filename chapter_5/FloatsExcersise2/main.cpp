#include <iostream>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

string getBinaryRepresentationOfFractal(double fractal);
string getBinaryRepresentationOfDecimalPart(const int& decimalPart);
string getBinaryRepresentationOfFractalPart(double fractalPart);

string getBinaryRepresentationOfFractal(double fractal)
{
    string result = "";
    int decimalPart = static_cast<int>(floor(fractal));

    result += getBinaryRepresentationOfDecimalPart(decimalPart);
    result += ".";
    result += getBinaryRepresentationOfFractalPart(fractal - decimalPart);

    return result;
}

string getBinaryRepresentationOfDecimalPart(const int& decimalPart)
{
    if(!decimalPart)
        return "00000000";

    string result = "";

    int divisionResult = decimalPart;
    while (divisionResult != 0)
    {
        if (divisionResult & 1)
            result += "1";
        else
            result += "0";

        divisionResult /= 2;
    }

    reverse(result.begin(), result.end());

    return result;
}

string getBinaryRepresentationOfFractalPart(double fractalPart)
{
    if(fractalPart == 0.0)
        return "00000000";

    string result = "";

    for (int i = 0; i < 8; ++i)
    {
        fractalPart *= 2.0;

        if(fractalPart >= 1.0){
            result += "1";
            fractalPart -= 1.0;
        }
        else{
            result += "0";
        }

    }

    return result;
}

int main()
{
    cout << getBinaryRepresentationOfFractal(0.125) << endl;
    cout << getBinaryRepresentationOfFractal(0.3) << endl;
    cout << getBinaryRepresentationOfFractal(2.17) << endl;
    cout << getBinaryRepresentationOfFractal(12.835) << endl;


    return 0;
}
