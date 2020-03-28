#include "pch.h"
#include "Account.h"

Account::Account(const int64_t& startupCapital)
{
    this->balance = startupCapital;
}

Account::~Account()
{
}

void Account::TransformAmountTo(const int64_t & amount, Account& targetAccount)
{
    this->LockAccountMutex();
    this->balance -= amount;

    targetAccount.LockAccountMutex();
    targetAccount.balance += amount;

    targetAccount.UnlockAccountMutex();
    this->UnlockAccountMutex();
}

void Account::UnlockAccountMutex()
{
    this->accountMutex.unlock();
}

void Account::LockAccountMutex()
{
    this->accountMutex.lock();
}
