#include "vipdeposit.h"

VipDeposit::VipDeposit(char *name, double startingBalance, int totalMonths)
    : Deposit(name, startingBalance, totalMonths),
      TermDeposit(name, startingBalance, totalMonths),
      OneOffDeposit(name, startingBalance, totalMonths)
{
    if (startingBalance > MaxBalance) startBalance = MaxBalance;
    if (balance > 5000) Percent = 0.2;
    else if (balance > 2000) Percent = 0.15;
}

VipDeposit::~VipDeposit() {}

void VipDeposit::GetProfit()
{
    struct tm *startParts = std::localtime(&startDate);
    struct tm *lastProfitParts = std::localtime(&lastProfitTime);

    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *nowParts = std::localtime(&now_c);
    int nowMonths = nowParts->tm_year * 12 + nowParts->tm_mon;
    int lastProfitMonths = lastProfitParts->tm_year * 12 + lastProfitParts->tm_mon;
    int startMonths = startParts->tm_year * 12 + startParts->tm_mon;
    if (nowMonths - lastProfitMonths > 1 && nowMonths - startMonths <= months) {
        balance += balance*Percent;
        lastProfitTime = now_c;
        if (balance > 5000) Percent = 0.2;
        else if (balance > 2000) Percent = 0.15;
    }
}

void VipDeposit::UpdateProfile(double popup)
{
    if (balance + popup > MaxBalance) return;
    balance += popup;
    if (balance > 5000) Percent = 0.2;
    else if (balance > 2000) Percent = 0.15;
}
