#ifndef BANKOMAT_H
#define BANKOMAT_H

#include "money.h"

class Bankomat
{
public:
    Bankomat();
    Bankomat(int moneyArr[]);
    ~Bankomat();
    Bankomat(Money *money);
    void PutMoney(Money *money);
    void TakeMoney(Money *money);
    Money * GetMoney() { return money; }
private:
    int id = rand()%10000;
    int maxMoneyArr[14] = {10, 10, 10, 10, 10, 100, 100, 100, 100, 100, 10, 10, 10, 10};
    Money * money;
    Money * maxMoney = new Money(maxMoneyArr);
    Money * minMoney = new Money();


};

#endif // BANKOMAT_H
