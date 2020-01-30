#include "debugger.hpp"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout<<"Please enter input program path: "<<endl;
    string path;
    std::getline( cin, path );

    Debugger debugger( path );
    debugger.startDebugging();

    return 0;
}
