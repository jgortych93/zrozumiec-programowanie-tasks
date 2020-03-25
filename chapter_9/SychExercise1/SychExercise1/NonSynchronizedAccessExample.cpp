#include "pch.h"
#include "NonSynchronizedAccessExample.h"

#include <iostream>
#include <thread>

uint8_t NonSynchronizedAccessExample::allThreadReadyLock = 0;

NonSynchronizedAccessExample::NonSynchronizedAccessExample()
{
    this->nonSynchronizedMap = new map< uint8_t, uint8_t >();
}


NonSynchronizedAccessExample::~NonSynchronizedAccessExample()
{
    delete this->nonSynchronizedMap;
}

void NonSynchronizedAccessExample::RunTest()
{
    thread* threads[THREADS_NUM];
    for (int i = 0; i < THREADS_NUM / 2; ++i)
    {
        threads[i] = new thread(&NonSynchronizedAccessExample::InsertToMap, this, (uint8_t)0, (uint8_t)i);
    }
    uint8_t j = 0;
    for (int i = THREADS_NUM / 2; i < THREADS_NUM ; ++i)
    {
        threads[i] = new thread(&NonSynchronizedAccessExample::DeleteFromMap, this, j);
        ++j;
    }

    for (int i = 0; i < THREADS_NUM; ++i)
    {
        threads[i]->join();
    }

    this->PrintMap();
}

void NonSynchronizedAccessExample::InsertToMap(const uint8_t& key, const uint8_t& value)
{
    pair<uint8_t, uint8_t> keyValuePair = { key, value };
    ++allThreadReadyLock;
    while (THREADS_NUM != allThreadReadyLock) {}
    this->nonSynchronizedMap->insert(keyValuePair);
}

void NonSynchronizedAccessExample::DeleteFromMap(const uint8_t & key)
{
    ++allThreadReadyLock;
    while (THREADS_NUM != allThreadReadyLock) {}
    this->nonSynchronizedMap->erase(key);
}

void NonSynchronizedAccessExample::PrintMap()
{
    cout << "Map content: " << endl;
    map< uint8_t, uint8_t >::iterator it = this->nonSynchronizedMap->begin();
    for ( it; it != this->nonSynchronizedMap->end(); ++it)
    {
        cout << to_string(it->second) << endl;
    }
}
