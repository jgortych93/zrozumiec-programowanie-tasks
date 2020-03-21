#include "pch.h"
#include "NonSynchronizedAccessExample.h"


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
}

void NonSynchronizedAccessExample::InsertToMap(const uint8_t & value)
{
}

void NonSynchronizedAccessExample::DeleteFromMap(const uint8_t & key)
{

}