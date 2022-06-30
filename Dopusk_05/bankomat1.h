#ifndef BANKOMAT1_H
#define BANKOMAT1_H

#include "money.h"

// агрегація

class Bankomat1
{
public:
    Bankomat1();
    Bankomat1(int moneyArr[]);
    Money * GetMoney() { return money; }
private:
    Money * money;
};

#endif // BANKOMAT1_H
