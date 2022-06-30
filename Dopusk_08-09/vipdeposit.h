#ifndef VIPDEPOSIT_H
#define VIPDEPOSIT_H

#include "termdeposit.h"
#include "oneoffdeposit.h"

class VipDeposit : public TermDeposit, public OneOffDeposit 
{
public:
    VipDeposit(char * name, double startingBalance, int totalMonths);
//    VipDeposit(char * name, char * password, double startingBalance);
    ~VipDeposit();

    void GetProfit() override; // перевизначення
    void UpdateProfile(double popup); // перевантаження
    using Deposit::UpdateProfile;
private:
    const double MaxBalance = 10000;
    
};

#endif // VIPDEPOSIT_H
