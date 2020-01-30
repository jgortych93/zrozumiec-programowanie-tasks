#include "debugger.hpp"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout<<"Please enter input program pid: "<<endl;
    string pidString;
    std::getline( cin, pidString );

    int pid = stoi( pidString );

    Debugger debugger( pid );
    debugger.startDebugging();

    return 0;
}
