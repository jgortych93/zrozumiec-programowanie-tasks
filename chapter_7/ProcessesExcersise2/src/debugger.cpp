#include "debugger.hpp"

#include <stdexcept>
#include <sys/types.h>
#include <unistd.h>

#define FORK_ERROR "Creating child process failed."

Debugger::Debugger( const string &path ) :processPath( path )
{
}

void Debugger::startDebugging() const
{
    pid_t pid = fork();

    switch( pid )
    {
        case 0:
            // child process
            this->handleChildProcess();
            break;
        case -1:
            throw runtime_error( FORK_ERROR );
            break;
        default:
            handleParentProcess();
            break;
    }
}

void Debugger::handleChildProcess() const
{

}

void Debugger::handleParentProcess() const
{
    s
}
