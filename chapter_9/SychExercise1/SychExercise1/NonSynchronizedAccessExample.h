#pragma once

#include <map>
#include <string>

using namespace std;

class NonSynchronizedAccessExample
{
public:
    NonSynchronizedAccessExample();
    ~NonSynchronizedAccessExample();
    void RunTest();

private:
    void InsertToMap(const uint8_t& value);
    void DeleteFromMap(const uint8_t& key);

    map< uint8_t, uint8_t >* nonSynchronizedMap;
};

