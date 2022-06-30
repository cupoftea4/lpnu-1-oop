#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <QDebug>

class Money
{
public:
    Money();
    Money(long uah, char coins);
    Money(Money &money);
    ~Money();
    std::string print();
    void SetMoney(long uah, char coins);
    void SetValue(double value);
    double GetValue() const;
    Money * operator+(Money const &money);
    Money * operator-(Money const &money);
    Money * operator/(Money const &money);
    Money * operator/(double num);
    Money * operator*(double num);
    bool operator>(Money const &money);
    bool operator<(Money const &money);
    bool operator==(Money const &money);

private:
    long * uah = new long();
    char * coins = new char();
    long GetUah() const;
    char GetCoins() const;

};

#endif // MONEY_H
