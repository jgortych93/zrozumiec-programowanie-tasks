#include <iostream>
#include <string>
#include "utf16toutf8converter.h"

using namespace std;

int main()
{
    u16string exampleString = u"Piktogram kota: \u0001f408";

    UTF16ToUTF8Converter *converter = new UTF16ToUTF8Converter();

    converter->convertToUTF8(exampleString);

    delete converter;

    return 0;
}
