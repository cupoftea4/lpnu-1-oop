#ifndef VIPACCOUNT_TNR_H
#define VIPACCOUNT_TNR_H

#include "bankaccount_tnr.h"
//#include "socialaccount_tnr.h"
#include <QTimer>

class VIPAccount_TNR : public BankAccount_TNR
{
    Q_OBJECT
public:
    VIPAccount_TNR();
    VIPAccount_TNR(QString login, QString password);
    bool TakeCredit(double amount);
    bool PayCredit(double amount);
    bool GetSocialPayment();
    double GetCreditLimit();
    double GetCredit();
    QString print();

signals:
    void CreditUpdatedSignal(double credit);

private:
    double credit = 0;
    bool canGetPayment = true;
    void AccrueInterest();
    const double CreditLimit = 1000;
    QTimer * timer;
private slots:
    void EnableSocialPayment();
};

#endif // VIPACCOUNT_TNR_H
