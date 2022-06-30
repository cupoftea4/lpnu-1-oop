#ifndef BANKACCOUNT_TNR_H
#define BANKACCOUNT_TNR_H

#include <QString>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QApplication>
#include "Account_TNR.h"

using std::string;

class BankAccount_TNR : public virtual Account_TNR
{
public:
    BankAccount_TNR(QString username, std::size_t password);
    BankAccount_TNR(QString username, QString password);
    ~BankAccount_TNR() override;
    QString print() override;
    int f() override;

private:

    bool GetSocialPayment() override { return false; };


};

#endif // BANKACCOUNT_TNR_H
