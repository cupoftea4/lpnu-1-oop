#include "bankomat1.h"

Bankomat1::Bankomat1()
{
    money = new Money();
}

Bankomat1::Bankomat1(int moneyArr[])
{
    money = new Money(moneyArr);
}
