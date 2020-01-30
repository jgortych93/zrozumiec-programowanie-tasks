#ifndef DEBUGGER_HPP
#define DEBUGGER_HPP

#include <string>

using namespace std;

class Debugger
{
    const int processToBeDebugged;
public:
    Debugger( const int &pid );
    void startDebugging() const;
private:
    void handleChildProcess( const pid_t &pid ) const;
    void handleParentProcess( const pid_t &pid ) const;
    const char* readProcessPath() const;
};

#endif // DEBUGGER_HPP
