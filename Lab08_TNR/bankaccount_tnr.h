#ifndef BANKACCOUNT_TNR_H
#define BANKACCOUNT_TNR_H

#include <QString>
#include <iostream>
#include <fstream>
#include <QObject>
#include <QDebug>
#include <QApplication>

using std::string;

class BankAccount_TNR : public QObject
{
    Q_OBJECT
public:
    BankAccount_TNR();
    BankAccount_TNR(QString login, QString password);
    ~BankAccount_TNR();
    double GetBalance();
    QList<QString> GetHistory();
    QString GetUsername();
    QString print();

    bool PayUtilities(double money);
    bool WithdrawCash(double money);
    bool TransferTo(BankAccount_TNR * account, double money);
    bool CheckAccount(QString username, QString password);

signals:
    void BalanceUpdatedSignal(double balance);
    void HistoryUpdatedSignal(QString str);

protected:
    QString login;
    std::size_t hashPassword;
    double balance;
    double utilitiesDebt;
    QList<QString> history;
    std::ofstream outdata;
    bool WithdrawMoney(double money);
    bool PutMoney(double money);
    void AddToHistory(QString str);
    const double Comission = 0.04;
    const double Percent = 0.01;
    const double MaxTransfer = 10000;
    const double MaxBalance = 100000;
    const int MillisecondsInHour = 1000;

private:
    double WithComission(double payment);

};

#endif // BANKACCOUNT_TNR_H
