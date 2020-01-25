#include "debugger.hpp"

#include <stdexcept>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>

#define FORK_ERROR "Creating child process failed."
#define PTRACE_ERROR "ptrace call failed"

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
            this->handleChildProcess( pid );
            break;
        case -1:
            throw runtime_error( FORK_ERROR );
        default:
            handleParentProcess( pid );
            break;
    }
}

void Debugger::handleChildProcess( const pid_t &pid ) const
{
    const long status = ptrace( PTRACE_TRACEME, pid, nullptr, nullptr );

    if ( -1 == status )
    {
        throw runtime_error( PTRACE_ERROR );
    }

    char* const path = const_cast<char* const>( this->processPath.c_str() );
    char* const args[] = { path };

    execve( this->processPath.c_str(), args, nullptr );

}

void Debugger::handleParentProcess( const pid_t &pid ) const
{

}
