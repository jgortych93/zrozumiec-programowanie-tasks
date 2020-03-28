#pragma once
#include <mutex>
#include <stdint.h>

class Account
{
public:
    Account(const int64_t& startupCapital);
    ~Account();

    void TransformAmountTo(const int64_t& amount, Account& targetAccount);
    void LockAccountMutex();
    void UnlockAccountMutex();
    int64_t balance;

private:
    std::mutex accountMutex;
};

