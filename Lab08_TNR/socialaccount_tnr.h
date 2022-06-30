#ifndef SOCIALACCOUNT_TNR_H
#define SOCIALACCOUNT_TNR_H

#include "bankaccount_tnr.h"
#include <QTimer>

class SocialAccount_TNR : public BankAccount_TNR
{
    Q_OBJECT
public:
    SocialAccount_TNR();
    SocialAccount_TNR(QString login, QString password);
    bool PayUtilities(double payment);
    bool GetSocialPayment();
    bool WithdrawCash(double money);
    QString print();

    using BankAccount_TNR::TransferTo;
    using BankAccount_TNR::GetHistory;
    using BankAccount_TNR::GetUsername;
    using BankAccount_TNR::CheckAccount;


protected:
    bool canGetPayment = true;
protected slots:
    void EnableSocialPayment();
};

#endif // SOCIALACCOUNT_TNR_H
