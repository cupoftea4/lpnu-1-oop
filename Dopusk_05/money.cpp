#include "money.h"
#include <QDebug>

Money::Money()
{
    sum = GetSum();
    coins = GetCoins();

}

Money::Money(int arrayOfBanknotesCounts[])
{
    countOf1 = arrayOfBanknotesCounts[0];
    countOf2 = arrayOfBanknotesCounts[1];
    countOf5 = arrayOfBanknotesCounts[2];
    countOf10 = arrayOfBanknotesCounts[3];
    countOf20 = arrayOfBanknotesCounts[4];
    countOf50 = arrayOfBanknotesCounts[5];
    countOf100 = arrayOfBanknotesCounts[6];
    countOf200 = arrayOfBanknotesCounts[7];
    countOf500 = arrayOfBanknotesCounts[8];
    countOfCoin1 = arrayOfBanknotesCounts[9];
    countOfCoin5 = arrayOfBanknotesCounts[10];
    countOfCoin10 = arrayOfBanknotesCounts[11];
    countOfCoin25 = arrayOfBanknotesCounts[12];
    countOfCoin50 = arrayOfBanknotesCounts[13];
    sum = GetSum();
    coins = GetCoins();
    for (int i = 0; i < 14; i++) {
        moneyCounts[i] = arrayOfBanknotesCounts[i];
    }
}

float Money::GetSum()
{
    sum = 500*countOf500 + 200*countOf200 + 100*countOf100 + 50*countOf50 + 20*countOf20 + 10*countOf10 +
            5*countOf5 + 2*countOf2 + countOf1 + 0.5*countOfCoin50 + 0.25*countOfCoin25 + 0.1*countOfCoin10 +
            0.05*countOfCoin5 + 0.01*countOfCoin1;
    return sum;
}

int Money::GetCoins()
{
    coins = 50*countOfCoin50 + 25*countOfCoin25 + 10*countOfCoin10 +
            5*countOfCoin5 + 1*countOfCoin1;
    return coins;
}

float Money::operator*(const float someSum)
{
    return sum * someSum;
}

float Money::operator/(const float someSum)
{
    return sum / someSum;
}

Money * Money::operator+(const Money &money)
{

    Money * money1 = new Money();
    money1->countOf1 = countOf1 + money.countOf1;
    money1->countOf2 = countOf2 + money.countOf2;
    money1->countOf5 = countOf5 + money.countOf5;
    money1->countOf10 = countOf10 + money.countOf10;
    money1->countOf20 = countOf20 + money.countOf20;
    money1->countOf50 = countOf50 + money.countOf50;
    money1->countOf100 = countOf100 + money.countOf100;
    money1->countOf200 = countOf200 + money.countOf200;
    money1->countOf500 = countOf500 + money.countOf500;
    money1->countOfCoin1 = countOfCoin1 + money.countOfCoin1;
    money1->countOfCoin5 = countOfCoin5 + money.countOfCoin5;
    money1->countOfCoin10 = countOfCoin10 + money.countOfCoin10;
    money1->countOfCoin25 = countOfCoin25 + money.countOfCoin25;
    money1->countOfCoin50 = countOfCoin50 + money.countOfCoin50;
    money1->sum = money1->GetSum();
    money1->coins = money1->GetCoins();

    return money1;
}

Money * Money::operator-(const Money &money)
{
    Money * money1 = new Money();
    money1->countOf1 = countOf1 - money.countOf1;
    money1->countOf2 = countOf2 - money.countOf2;
    money1->countOf5 = countOf5 - money.countOf5;
    money1->countOf10 = countOf10 - money.countOf10;
    money1->countOf20 = countOf20 - money.countOf20;
    money1->countOf50 = countOf50 - money.countOf50;
    money1->countOf100 = countOf100 - money.countOf100;
    money1->countOf200 = countOf200 - money.countOf200;
    money1->countOf500 = countOf500 - money.countOf500;
    money1->countOfCoin1 = countOfCoin1 - money.countOfCoin1;
    money1->countOfCoin5 = countOfCoin5 - money.countOfCoin5;
    money1->countOfCoin10 = countOfCoin10 - money.countOfCoin10;
    money1->countOfCoin25 = countOfCoin25 - money.countOfCoin25;
    money1->countOfCoin50 = countOfCoin50 - money.countOfCoin50;
    money1->sum = money1->GetSum();
    money1->coins = money1->GetCoins();

    return money1;
}

bool Money::operator==(const Money &money)
{
    return (money.sum == this->GetSum());
}

bool Money::operator>(const Money &money)
{
    bool isGreater = (countOf1 > money.countOf1) || (countOf2 > money.countOf2) || (countOf5 > money.countOf5)
            || (countOf10 > money.countOf10) || (countOf20 > money.countOf20) || (countOf50 > money.countOf50)
            || (countOf100 > money.countOf100) || (countOf200 > money.countOf200) || (countOf500 > money.countOf500)
            || (countOfCoin1 > money.countOfCoin1) || (countOfCoin5 > money.countOfCoin5) || (countOfCoin10 > money.countOfCoin10)
            || (countOfCoin25 > money.countOfCoin25) || (countOfCoin50 > money.countOfCoin50);
    return isGreater;
}

bool Money::operator<(const Money &money)
{
    bool isLess = (countOf1 < money.countOf1) || (countOf2 < money.countOf2) || (countOf5 < money.countOf5)
            || (countOf10 < money.countOf10) || (countOf20 < money.countOf20) || (countOf50 < money.countOf50)
            || (countOf100 < money.countOf100) || (countOf200 < money.countOf200) || (countOf500 < money.countOf500)
            || (countOfCoin1 < money.countOfCoin1) || (countOfCoin5 < money.countOfCoin5) || (countOfCoin10 < money.countOfCoin10)
            || (countOfCoin25 < money.countOfCoin25) || (countOfCoin50 < money.countOfCoin50);
    return isLess;
}

void Money::PrintToConsole()
{
    float coinsSum = coins/100.0;
    qDebug() << sum - coinsSum + floor(coinsSum) << "," << coins%100;
}

