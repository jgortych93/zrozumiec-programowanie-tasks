#include <exception>
#include <iostream>

#include "processexplorer.h"

using namespace std;

int main()
{
    ProcessExplorer processExplorer;

    try
    {
        processExplorer.getProcessesInfo();
    }
    catch ( exception ex )
    {
        cerr<<ex.what();
    }

    return 0;
}
