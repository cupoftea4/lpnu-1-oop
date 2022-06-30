#include "oneoffdeposit.h"


OneOffDeposit::OneOffDeposit(char * name, double startingBalance, int totalMonths) : Deposit(name, startingBalance, totalMonths) {}

OneOffDeposit::~OneOffDeposit() {}

void OneOffDeposit::GetProfit()
{
    struct tm *startParts = std::localtime(&startDate);

    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *nowParts = std::localtime(&now_c);

    if ((nowParts->tm_year*12 + nowParts->tm_mon) - (startParts->tm_year * 12 + startParts->tm_mon) == months && !gotProfit) {
        balance += balance*Percent;
        gotProfit = true;
    }
}

void OneOffDeposit::UpdateProfile(char *password)
{
    strcpy(this->password, password);
}
