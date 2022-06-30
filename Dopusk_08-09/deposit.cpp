#include "deposit.h"

Deposit::Deposit(char *name, double startingBalance, int totalMonths)
{
    strcpy(this->name, name);
    startBalance = startingBalance;
    months = totalMonths;
    auto now = Clock::now();
    startDate = Clock::to_time_t(now);
}

Deposit::Deposit()
{
    auto now = Clock::now();
    startDate = Clock::to_time_t(now);
}

Deposit::~Deposit()
{
    delete [] name;
}

void Deposit::UpdateProfile(char *name, char *password)
{
   strcpy(this->name, name);
   strcpy(this->password, password);
}
