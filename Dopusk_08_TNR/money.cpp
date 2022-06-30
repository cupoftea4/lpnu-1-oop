#include "money.h"

Money::Money(){}

Money::Money(long uah, char coins)
{
    *(this->coins) = coins;
    *(this->uah) = uah;
}

Money::Money(Money &money)
{
    *coins = *money.coins;
    *uah = *money.uah;
}

Money::~Money()
{
    delete uah;
    delete coins;
}

std::string Money::print()
{
    return std::to_string(*uah) + "," + std::to_string(*coins);
}

void Money::SetMoney(long uah, char coins)
{
    *this->uah = uah;
    *this->coins = coins;
}

void Money::SetValue(double value)
{
    double intpart;
    *coins = modf(value, &intpart) * 100;
    *uah = intpart;
}

long Money::GetUah() const
{
    return *uah;
}

char Money::GetCoins() const
{
    return *coins;
}

double Money::GetValue() const
{
     return GetUah() + GetCoins() / 100.0;
}

Money * Money::operator+(Money const &money) {
    Money * res = new Money();
    res->SetMoney(money.GetUah() + *uah, money.GetCoins() + *coins);
    return res;

}

Money * Money::operator-(Money const &money) {
    Money * res = new Money();
    res->SetMoney(money.GetCoins() - *uah, money.GetCoins() - *coins);
    return res;

}

Money * Money::operator/(Money const &money) {
    Money * res = new Money();
    res->SetValue(GetValue() / money.GetValue());
    return res;
}

Money * Money::operator/(double num) {
    Money * res = new Money();
    res->SetValue(GetValue() / num);
    return res;
}

Money * Money::operator*(double num) {
    Money * res = new Money();
    res->SetValue(GetValue() * num);
    return res;
}

bool Money::operator>(Money const &money) {
    return GetValue() > money.GetValue();
}

bool Money::operator<(Money const &money) {
    return GetValue() < money.GetValue();
}

bool Money::operator==(Money const &money) {
    return GetValue() == money.GetValue();
}

