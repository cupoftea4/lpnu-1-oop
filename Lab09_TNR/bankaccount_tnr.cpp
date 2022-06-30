#include "bankaccount_tnr.h"

BankAccount_TNR::BankAccount_TNR(QString username, std::size_t password) : Account_TNR(username, password) {}

BankAccount_TNR::BankAccount_TNR(QString username, QString password) : Account_TNR(username, password)  {}

BankAccount_TNR::~BankAccount_TNR()
{
    outdata.close();
}

QString BankAccount_TNR::print()
{
    return "BankAccount_TNR";
}


