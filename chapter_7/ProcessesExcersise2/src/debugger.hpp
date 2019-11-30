#ifndef DEBUGGER_HPP
#define DEBUGGER_HPP

#include <string>

using namespace std;

class Debugger
{
    const string processPath;
public:
    Debugger( const string &path );
    void startDebugging() const;
private:
    void handleChildProcess() const;
    void handleParentProcess() const;
};

#endif // DEBUGGER_HPP
