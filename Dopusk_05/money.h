#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <math.h>
using namespace std;


class Money
{
public:
    Money();
    Money(int arrayOfBanknotesCounts[]);

    float GetSum();
    int GetCoins();

    float operator*(const float someSum);
    float operator/(const float someSum);

    Money * operator+(const Money &money);
    Money * operator-(const Money &money);

    bool operator==(const Money &money);
    bool operator>(const Money &money);
    bool operator<(const Money &money);

    friend ostream& operator<<(ostream& os, const Money& money) {
        float coinsSum = money.coins/100.0;
        os << money.sum - coinsSum + floor(coinsSum) << "," << money.coins%100;
        return os;
    };

    void PrintToConsole();

private:
    int countOf1 = 0;
    int countOf2 = 0;
    int countOf5 = 0;
    int countOf10 = 0;
    int countOf20 = 0;
    int countOf50 = 0;
    int countOf100 = 0;
    int countOf200 = 0;
    int countOf500 = 0;
    int countOfCoin1 = 0;
    int countOfCoin5 = 0;
    int countOfCoin10 = 0;
    int countOfCoin25 = 0;
    int countOfCoin50 = 0;
    float sum;
    int coins;
    int moneyCounts[14];
};

#endif // MONEY_H
