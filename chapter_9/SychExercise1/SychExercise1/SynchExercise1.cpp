// SynchExercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "NonSynchronizedAccessExample.h"

#include <iostream>

int main()
{
    //First example shows that non synchronized operations are untrusty as the result cannot be predicted
    NonSynchronizedAccessExample firstProblem;
    firstProblem.RunTest();
}