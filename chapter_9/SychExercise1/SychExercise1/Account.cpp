#include "pch.h"
#include "Account.h"

Account::Account(const int64_t& startupCapital)
{
    this->balance = startupCapital;
}

Account::~Account()
{
}

void Account::TransformAmountTo(int64_t amount, Account& targetAccount)
{
    this->LockAccountMutex();
    this->balance -= amount;

    targetAccount.LockAccountMutex();
    targetAccount.balance += amount;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    targetAccount.UnlockAccountMutex();
    this->UnlockAccountMutex();
}

void Account::TransformAmountToSynchronized(const int64_t & amount, Account & targetAccount)
{
    std::lock(this->accountMutex, targetAccount.accountMutex);
    std::lock_guard<std::mutex> lockFrom(this->accountMutex, std::adopt_lock);
    std::lock_guard<std::mutex> targetLock(targetAccount.accountMutex, std::adopt_lock);

    this->balance -= amount;
    targetAccount.balance += amount;
}

void Account::UnlockAccountMutex()
{
    this->accountMutex.unlock();
}

void Account::LockAccountMutex()
{
    this->accountMutex.lock();
}
