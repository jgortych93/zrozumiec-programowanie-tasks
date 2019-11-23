#include "processexplorer.h"

#include <algorithm>

#define PROC_DIR_PATH "/proc/"
#define ERROR_MESSAGE "PROC DIR CANNOT BE OPENED"

void ProcessExplorer::getProcessesInfo() const
{
    DIR* dir;
    struct dirent* entry;

    if( nullptr != (dir = opendir( PROC_DIR_PATH )) )
    {
        while( nullptr != (entry = readdir( dir )) )
        {
            if( isStringNumeric( entry->d_name ) )
            {
                ProcessInfo procInfo;
                procInfo.pid = entry->d_name;

                this->displayInfo( procInfo );
            }
        }
    }
    else
    {
        cerr<<ERROR_MESSAGE;
    }
}

string ProcessExplorer::getProcessName( const struct dirent& entry ) const
{
    return entry.d_name;
}

void ProcessExplorer::displayInfo( const ProcessInfo& procInfo ) const
{
    cout<<"Process id: "<<procInfo.pid<<endl;
}

bool ProcessExplorer::isStringNumeric( const string &dirName ) const
{
    return find_if( dirName.begin(), dirName.end(), []( char c ) { return !isdigit( c ); } ) == dirName.end();
}
