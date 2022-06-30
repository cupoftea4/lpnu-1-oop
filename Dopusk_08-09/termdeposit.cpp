#include "termdeposit.h"


TermDeposit::TermDeposit(char *name, double startingBalance, int months) : Deposit(name, startingBalance, months) {}

TermDeposit::~TermDeposit(){ }

void TermDeposit::GetProfit()
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
    }
}

void TermDeposit::UpdateProfile(int additionalMonths)
{
    months += additionalMonths;
}
