#ifndef VIPACCOUNT_TNR_H
#define VIPACCOUNT_TNR_H

#include "bankaccount_tnr.h"
#include "socialaccount_tnr.h"


class VIPAccount_TNR : public SocialAccount_TNR, public BankAccount_TNR
{
public:
    VIPAccount_TNR(QString login, QString password);

    double GetCredit();
    double GetCreditLimit();

    bool TakeCredit(double amount);
    bool PayCredit(double amount);
    bool GetSocialPayment() override;
    QString print() override;

private:
    double credit = 0;
    void AccrueInterest();
    QTimer * timer;
    void EnableSocialPayment();
};

#endif // VIPACCOUNT_TNR_H
