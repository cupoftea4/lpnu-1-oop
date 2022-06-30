#ifndef TERMDEPOSIT_H
#define TERMDEPOSIT_H

#include "deposit.h"

class TermDeposit : public virtual Deposit
{
public:
    TermDeposit(char * name, double startingBalance, int months);
    ~TermDeposit();
    void GetProfit() override; // перевизначення
    void UpdateProfile(int additionalMonths); // перевантаження
    using Deposit::UpdateProfile;
protected:
    std::time_t lastProfitTime = startDate;
};

#endif // TERMDEPOSIT_H
