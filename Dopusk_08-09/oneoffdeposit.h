#ifndef ONEOFFDEPOSIT_H
#define ONEOFFDEPOSIT_H

#include "deposit.h"

class OneOffDeposit : public virtual Deposit
{
public:
    OneOffDeposit(char * name, double startingBalance, int totalMonths);
    ~OneOffDeposit();
    void GetProfit() override; // перевизначення
    void UpdateProfile(char * password); // перевантаження
    using Deposit::UpdateProfile;
private:
    bool gotProfit = false;
};

#endif // ONEOFFDEPOSIT_H
