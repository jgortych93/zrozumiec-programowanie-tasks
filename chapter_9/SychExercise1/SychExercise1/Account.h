#pragma once
#include <mutex>
#include <stdint.h>

class Account
{
public:
    Account(const int64_t& startupCapital);
    ~Account();

    void TransformAmountTo(int64_t amount, Account& targetAccount);
    void TransformAmountToSynchronized(const int64_t& amount, Account& targetAccount);
    void LockAccountMutex();
    void UnlockAccountMutex();
    int64_t balance;
    std::mutex accountMutex;
};

