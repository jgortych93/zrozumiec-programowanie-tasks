#include "debugger.hpp"
#include "registry_read_instructions.hpp"

#include <errno.h>
#include <iostream>
#include <string.h>

#include <sys/syscall.h>
#include <stdexcept>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>

using namespace std;

#define FORK_ERROR "Creating child process failed."
#define PATH_BUFFER_SIZE 25
#define PTRACE_ERROR "ptrace call failed"
#define READLINK_ERROR "Readlink operation failed."

Debugger::Debugger( const int &pid ) :processToBeDebugged( pid )
{
}

void Debugger::startDebugging() const
{
    pid_t pid = fork();
    cout<<"Pid:"<<pid<<endl;

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
    const char* processPath = this->readProcessPath();

    if ( -1 == status )
    {
        throw runtime_error( PTRACE_ERROR );
    }

    char* const path = const_cast<char* const>( processPath );
    char* const args[] = { path };

    execve( processPath, args, nullptr );

}

void Debugger::handleParentProcess( const pid_t &pid ) const
{
    struct user_regs_struct regs;
    int status;
    long lastCall;

    while( waitpid( pid, &status, 0 ) && !WIFEXITED( status ) )
    {
        ptrace( PTRACE_GETREGS, pid, NULL, &regs );
        lastCall = LASTCALL( regs );

        if( SYS_write == lastCall )
        {
            cout<<"Process id: "<<pid<<" - syscall write: "<<lastCall<<endl;
            cout<<"File descriptor: "<<FD( regs )<<"------ Text buffer: "<<TEXT_ADDRESS( regs )<<"------ Text size: "<< COUNT( regs )<<endl;
        }
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
    }
}

const char *Debugger::readProcessPath() const
{
    char* pathBuffer = new char( PATH_BUFFER_SIZE );

    string pathname = "/proc/";
    pathname.append( to_string( this->processToBeDebugged ) );
    pathname.append( "/exe" );

    const int sizeWritten = readlink( pathname.c_str(), pathBuffer, PATH_BUFFER_SIZE - 1 );
    if( -1 == sizeWritten )
    {
        cout<<READLINK_ERROR<<": "<<strerror( errno )<<" for path: "<<pathname<<endl;
        throw runtime_error( READLINK_ERROR );
    }

    pathBuffer[sizeWritten] = '\0';

    return pathBuffer;
}
