#include "vipaccount_tnr.h"


VIPAccount_TNR::VIPAccount_TNR(QString login, QString password)
    : Account_TNR(login, password),
      SocialAccount_TNR(login, password),
      BankAccount_TNR(login, password) { CreditLimit = 10000;  canGetPayment = true;}

bool VIPAccount_TNR::TakeCredit(double money)
{
    if (credit + money < CreditLimit && PutMoney(money)){
        credit += money;
        AddToHistory(QString::asprintf("Your took %f uah of credit", money));
        signalEmitter->EmitCreditUpdate(credit);
//        QObject::connect(signalEmitter, &SignalEmitter::TimeoutSignal, this, &VIPAccount_TNR::AccrueInterest);
        signalEmitter->timer->start(MillisecondsInHour);
        return true;
    }
    AddToHistory(QString::asprintf("Your failed to take %f uah credit. Probably you reached credit limit.", money));
    return false;
}

bool VIPAccount_TNR::PayCredit(double amount)
{
    double payment = std::min(amount, credit);
    if (WithdrawMoney(payment)) {
        AddToHistory(QString::asprintf("Your loan decreased by %f uah", payment));
        credit -= payment;
        signalEmitter->EmitCreditUpdate(credit);
        return true;
    }
    AddToHistory("You failed to pay for loan");
    return false;
}

void VIPAccount_TNR::AccrueInterest() {
    if (credit <= 0) {
        timer->stop();
        return;
    }
    credit += credit * Percent;
    AddToHistory(QString::asprintf("Your loan increased by %f uah", credit * Percent));
    signalEmitter->EmitCreditUpdate(credit);
}

void VIPAccount_TNR::EnableSocialPayment()
{
    canGetPayment = true;
}

bool VIPAccount_TNR::GetSocialPayment()
{
    double percent = Percent;
    if (balance >= 10000) {
        percent = 0.05;
    } else if (balance >= 50000) {
        percent = 0.1;
    }

    if (canGetPayment) {
        canGetPayment = false;
//        QTimer::singleShot(MillisecondsInHour, this, SLOT(EnableSocialPayment()));
        if (PutMoney(balance * percent)) {
            AddToHistory(QString::asprintf("You got %f uah(social payment)", balance * percent));
            return true;
        } else {
            AddToHistory("You failed to get social payment. Too large balance");
            return false;
        }
    }
    AddToHistory("You tried to get social payment too soon.");
    return false;

}

double VIPAccount_TNR::GetCreditLimit()
{
    return CreditLimit;
}

double VIPAccount_TNR::GetCredit()
{
    return credit;
}

QString VIPAccount_TNR::print()
{
    return "VIPAccount_TNR";
}
