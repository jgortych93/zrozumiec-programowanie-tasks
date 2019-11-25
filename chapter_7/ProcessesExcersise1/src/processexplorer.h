#ifndef PROCESSEXPLORER_H
#define PROCESSEXPLORER_H

#include "processinfo.h"

#include <dirent.h>
#include <iostream>
#include <stdio.h>
using namespace std;


class ProcessExplorer
{
public:
    void getProcessesInfo() const;
private:
    void displayInfo( const ProcessInfo& procInfo ) const;
    string getProcessName( const struct dirent& entry ) const;
    bool isStringNumeric( const string& dirName ) const;
    void displayProcessStatus( const struct dirent& entry ) const;
};

#endif // PROCESSEXPLORER_H
