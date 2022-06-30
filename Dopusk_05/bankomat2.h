#ifndef BANKOMAT2_H
#define BANKOMAT2_H

#include "money.h"

// композиція

class Bankomat2
{
public:
    Bankomat2();
    Bankomat2(Money * money);
    Money * GetMoney() { return money; }
private:
    Money * money;
};

#endif // BANKOMAT2_H
