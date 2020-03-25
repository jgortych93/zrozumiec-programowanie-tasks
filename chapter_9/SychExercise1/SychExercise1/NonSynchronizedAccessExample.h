#pragma once

#include <map>
#include <string>

#define THREADS_NUM 12

using namespace std;

class NonSynchronizedAccessExample
{
public:
    NonSynchronizedAccessExample();
    ~NonSynchronizedAccessExample();
    void RunTest();

private:
    void InsertToMap(const uint8_t& key, const uint8_t& value);
    void DeleteFromMap(const uint8_t& key);
    void PrintMap();

    map< uint8_t, uint8_t >* nonSynchronizedMap;

    static uint8_t allThreadReadyLock;
};

