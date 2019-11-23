#include "processexplorer.h"

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
            ProcessInfo* procInfo = new ProcessInfo();
            procInfo->name = this->getProcessName( entry );

            this->displayInfo( procInfo );
            delete procInfo;
        }
    }
    else
    {
        cerr<<ERROR_MESSAGE;
    }
}

string ProcessExplorer::getProcessName(const struct dirent *entry) const
{
    return entry->d_name;
}

void ProcessExplorer::displayInfo( ProcessInfo* procInfo ) const
{
    cout<<"Process id: "<<procInfo->name<<endl;
}
