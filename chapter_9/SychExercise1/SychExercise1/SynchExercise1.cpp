// SynchExercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Account.h"
#include "NonSynchronizedAccessExample.h"

#include <iostream>
#include <thread>

using namespace std;

int main()
{
    cout << "Please choose which example to show: " << endl;
    cout << "First example shows that non synchronized operations are untrusty as the result cannot be predicted" << endl;
    cout << "Second example shows the risk of thread deadlocking while two mutexes are being locked by different threads in opposite orders" << endl;
    uint8_t chosenOption = 0U;
    cin >> chosenOption;

    switch (chosenOption)
    {
    case 1:
    {
        NonSynchronizedAccessExample firstProblem;
        firstProblem.RunTest();
        break;
    }
    case 2:
    {
        Account firstAccount(30000);
        Account secondAccount(50000);
        thread *firstThread = new thread(&Account::TransformAmountTo, &firstAccount, 10000, secondAccount);
        thread *secondThread = new thread(&Account::TransformAmountTo, &secondAccount, 55000, firstAccount);

        firstThread->join();
        secondThread->join();

        delete firstThread;
        delete secondThread;
        break;
    }
    default:
        cout << "Wrong option." << endl;
        main();
        return 0;
    }

}