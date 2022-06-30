#include "socialaccount_tnr.h"

SocialAccount_TNR::SocialAccount_TNR(QString username, std::size_t password) : Account_TNR(username, password) { canGetPayment = true; }

SocialAccount_TNR::SocialAccount_TNR(QString username, QString password) : Account_TNR(username, password) { canGetPayment = true; }



bool SocialAccount_TNR::GetSocialPayment()
{
    if (canGetPayment) {
        canGetPayment = false;
//        QTimer::singleShot(MillisecondsInHour, this, SLOT(EnableSocialPayment()));
        if (PutMoney(balance * Percent)) {
            AddToHistory(QString::asprintf("You got %f uah(social payment)", balance * Percent));
            return true;
        } else {
            AddToHistory("You failed to get social payment. Too large balance");
            return false;
        }
    }
    AddToHistory("You tried to get social payment too soon.");
    return false;

}


QString SocialAccount_TNR::print()
{
    return "SocialAccount_TNR";
}

void SocialAccount_TNR::EnableSocialPayment()
{
    canGetPayment = true;
}

bool SocialAccount_TNR::PayUtilities(double amount)
{
    double payment = std::min(amount, utilitiesDebt);
    if (amount < MaxTransfer && WithdrawMoney(payment)) {
        AddToHistory(QString::asprintf("You paid utilities for %f uah(without comission)", payment));
        return true;
    }
    AddToHistory(QString::asprintf("You failed to pay utilities for %f uah", payment));
    return false;
}


bool SocialAccount_TNR::WithdrawCash(double money)
{
    qDebug() << "Withdraw Cash";
    if (money < MaxTransfer && WithdrawMoney(money)) {
        AddToHistory(QString::asprintf("You withdrawed %f uah", money));
        return true;
    }
    AddToHistory(QString::asprintf("You failed to withdraw %f uah", money));
    return false;
}
