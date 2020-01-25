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
    void handleChildProcess( const pid_t &pid ) const;
    void handleParentProcess( const pid_t &pid ) const;
};

#endif // DEBUGGER_HPP
