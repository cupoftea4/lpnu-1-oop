#ifndef ACCOUNT_TNR_H
#define ACCOUNT_TNR_H

#include <QString>
#include <iostream>
#include <fstream>
#include <QObject>
#include <QDebug>
#include <QApplication>
#include <QDateTime>
#include "signalemitter.h"

class Account_TNR
{
public:
    Account_TNR(QString username, std::size_t password);
    Account_TNR(QString username, QString password);
    virtual ~Account_TNR();
    double GetBalance();
    QList<QString> GetHistory();
    QString GetUsername();

    bool CheckAccount(QString username, QString password);
    bool TransferTo(Account_TNR * account, double money);
    virtual bool PayUtilities(double money);
    virtual bool WithdrawCash(double money);
    virtual bool GetSocialPayment() = 0;
    virtual QString print() = 0;
    virtual int f();
    bool CanGetPayment() {return canGetPayment;}

    double CreditLimit = -1;
    SignalEmitter * signalEmitter;

protected:
    bool canGetPayment = false;
    QString login;
    std::size_t hashPassword;
    double balance;
    double utilitiesDebt;
    QList<QString> history;
    std::ofstream outdata;

    bool WithdrawMoney(double money);
    bool PutMoney(double money);
    void AddToHistory(QString str);
    void CreateAccount(QString username, std::size_t password);

    const double Comission = 0.04;
    const double Percent = 0.01;
    const double MaxTransfer = 10000;
    const double MaxBalance = 100000;
    const int MillisecondsInHour = 1000;
private:
    double WithComission(double payment);

};

#endif // ACCOUNT_TNR_H
