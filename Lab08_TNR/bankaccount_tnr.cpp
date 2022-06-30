#include "bankaccount_tnr.h"

BankAccount_TNR::BankAccount_TNR()
{
    balance = 0;
    utilitiesDebt = 0;
}

BankAccount_TNR::BankAccount_TNR(QString login, QString password) : login(login)
{
    balance = 100;
    utilitiesDebt = 20;
    hashPassword = std::hash<std::string>{}(password.toStdString());
    outdata.open("amy.txt", std::ofstream::out | std::ofstream::app);
}

BankAccount_TNR::~BankAccount_TNR()
{
    outdata.close();
}

double BankAccount_TNR::GetBalance()
{
    return balance;
}

QList<QString> BankAccount_TNR::GetHistory()
{
    return history;
}

QString BankAccount_TNR::GetUsername()
{
    return login;
}

QString BankAccount_TNR::print()
{
    return "BankAccount_TNR";
}

bool BankAccount_TNR::PayUtilities(double amount)
{
    double payment = std::min(amount, utilitiesDebt);
    if (amount < MaxTransfer && WithdrawMoney(WithComission(payment))) {
        AddToHistory(QString::asprintf("You paid utilities for %f uah(comission: %f)",
                                         payment, WithComission(payment) - payment));
        return true;
    } else {
        AddToHistory(QString::asprintf("You failed to pay utilities for %f uah", payment));
        return false;
    }
}

bool BankAccount_TNR::TransferTo(BankAccount_TNR *account, double money)
{
    if (money < MaxTransfer && account->PutMoney(money) && WithdrawMoney(money)) {
        AddToHistory(QString::asprintf("You tranfered %f uah to %s", money, account->GetUsername().toLocal8Bit().data()));
        return true;
    } else {
        AddToHistory(QString::asprintf("You failed to transfer %f uah to %s", money, account->GetUsername().toLocal8Bit().data()));
        return false;
    }
}

bool BankAccount_TNR::WithdrawCash(double money)
{
    if (money < MaxTransfer && WithdrawMoney(WithComission(money))) {
        AddToHistory(QString::asprintf("You withdrawed %f uah(comission: %f)",
                                       money, WithComission(money) - money));
        return true;
    }
    AddToHistory(QString::asprintf("You failed to withdraw %f uah", money));
    return false;
}

bool BankAccount_TNR::CheckAccount(QString username, QString password)
{

    return login == username && this->hashPassword == std::hash<std::string>{}(password.toStdString());
}

bool BankAccount_TNR::WithdrawMoney(double money)
{
    if (money < 0 || balance - money < 0) return false;
    balance -= money;
    emit BalanceUpdatedSignal(balance);
    return true;
}

bool BankAccount_TNR::PutMoney(double money)
{
    if (money < 0 || balance + money > MaxBalance) return false;
    balance += money;
    emit BalanceUpdatedSignal(balance);
    return true;
}

void BankAccount_TNR::AddToHistory(QString str)
{
//    QDateTime setTime = QDateTime::fromString (QString("1970-07-18T14:15:09"), Qt::ISODate);
//    QDateTime current = QDateTime::currentDateTime();
//    uint msecs = setTime.time().msecsTo(current.time());
    outdata <<  str.toStdString() + "\n";
    history.append(str);
    emit HistoryUpdatedSignal(str);
}

double BankAccount_TNR::WithComission(double payment)
{
    return payment + payment * Comission;
}

