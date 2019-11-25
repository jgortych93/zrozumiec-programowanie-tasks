#include "processexplorer.h"

#include <algorithm>
#include <fstream>
#include <limits.h>
#include <stdexcept>
#include <stdlib.h>
#include <string>

#define PROC_DIR_PATH "/proc/"
#define PROC_NO_ACCESS_MESSAGE "PROC DIR CANNOT BE OPENED"
#define COMM_FILE_NO_ACCESS_MESSAGE "Comm file cannot be opened"


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
                procInfo.name = this->getProcessName( *entry );

                this->displayInfo( procInfo );
            }
        }
    }
    else
    {
        cerr<<PROC_NO_ACCESS_MESSAGE;
    }
}

string ProcessExplorer::getProcessName( const struct dirent& entry ) const
{
    ifstream inputFile;
    string commFilePath( PROC_DIR_PATH );
    commFilePath.append( entry.d_name );
    commFilePath.append( "/comm" );
    inputFile.open( commFilePath );
    if( inputFile.is_open() )
    {
        string line;
        getline( inputFile, line );
        inputFile.close();
        return line;
    }
    else
    {
        cerr<<COMM_FILE_NO_ACCESS_MESSAGE<<endl;
        throw runtime_error( COMM_FILE_NO_ACCESS_MESSAGE );
    }
}

void ProcessExplorer::displayInfo( const ProcessInfo& procInfo ) const
{
    cout<<"Process id: "<<procInfo.pid<<endl;
    cout<<"\tName: "<<procInfo.name<<endl;
}

bool ProcessExplorer::isStringNumeric( const string &dirName ) const
{
    return find_if( dirName.begin(), dirName.end(), []( char c ) { return !isdigit( c ); } ) == dirName.end();
}
