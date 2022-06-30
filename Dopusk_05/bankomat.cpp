#include "bankomat.h"

Bankomat::Bankomat()
{
    money = new Money();
    id = rand()%10000;
}

Bankomat::Bankomat(int moneyArr[])
{
    money = new Money(moneyArr);
    id = rand()%10000;}

Bankomat::~Bankomat()
{

}

Bankomat::Bankomat(Money * money)
{
    this->money = money;
    id = rand()%10000;
}

void Bankomat::PutMoney(Money *moneyToPut)
{
    if ((*money + *moneyToPut) > maxMoney) return;
    money = *money + *moneyToPut;

}

void Bankomat::TakeMoney(Money *moneyToTake)
{
    if ((*money - *moneyToTake) < minMoney) return;
    money = *money - *moneyToTake;

}





