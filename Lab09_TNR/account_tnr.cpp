#include "Account_TNR.h"

Account_TNR::Account_TNR(QString username, std::size_t password)
{
    CreateAccount(username, password);
    signalEmitter = new SignalEmitter(username);
    outdata.open((username + ".txt").toStdString(), std::ofstream::out );
}

Account_TNR::Account_TNR(QString username, QString password)
{
    CreateAccount(username, std::hash<std::string>{}(password.toStdString()));
    signalEmitter = new SignalEmitter(username);
    outdata.open((username + ".txt").toStdString(), std::ofstream::out );
}

Account_TNR::~Account_TNR()
{
    delete signalEmitter;
}

bool Account_TNR::CheckAccount(QString username, QString password)
{
    qDebug() << login << " " << username;
    qDebug() << hashPassword << " " << std::hash<std::string>{}(password.toStdString());
    return login == username && this->hashPassword == std::hash<std::string>{}(password.toStdString());
}

bool Account_TNR::WithdrawMoney(double money)
{
    if (money < 0 || balance - money < 0) return false;
    balance -= money;
    signalEmitter->EmitBalanceUpdate(balance);
    return true;
}

bool Account_TNR::PutMoney(double money)
{
    if (money < 0 || balance + money > MaxBalance) return false;
    balance += money;
    signalEmitter->EmitBalanceUpdate(balance);
    return true;
}

void Account_TNR::AddToHistory(QString str)
{
    QDateTime current = QDateTime::currentDateTime();
    str = current.toString("[HH:mm:ss]") + " " + str;
    outdata << str.toStdString() + "\n";
    history.append(str);
    signalEmitter->EmitHistoryUpdate(str);
}

void Account_TNR::CreateAccount(QString username, std::size_t password)
{
    this->login = username;
    balance = 100;
    utilitiesDebt = 100;
    hashPassword = password;
}


double Account_TNR::GetBalance()
{
    return balance;
}

QList<QString> Account_TNR::GetHistory()
{
    return history;
}

QString Account_TNR::GetUsername()
{
    return login;
}

bool Account_TNR::TransferTo(Account_TNR *account, double money)
{
    if (money < MaxTransfer && account->PutMoney(money) && WithdrawMoney(money)) {
        AddToHistory(QString::asprintf("You tranfered %f uah to %s", money, account->GetUsername().toLocal8Bit().data()));
        return true;
    } else {
        AddToHistory(QString::asprintf("You failed to transfer %f uah to %s", money, account->GetUsername().toLocal8Bit().data()));
        return false;
    }
}


bool Account_TNR::PayUtilities(double amount)
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



bool Account_TNR::WithdrawCash(double money)
{
    if (money < MaxTransfer && WithdrawMoney(WithComission(money))) {
        AddToHistory(QString::asprintf("You withdrawed %f uah(comission: %f)",
                                       money, WithComission(money) - money));
        return true;
    }
    AddToHistory(QString::asprintf("You failed to withdraw %f uah", money));
    return false;
}



double Account_TNR::WithComission(double payment)
{
    return payment + payment * Comission;
}
