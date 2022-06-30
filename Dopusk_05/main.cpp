#include <QCoreApplication>

#include "money.h"
#include "bankomat1.h"
#include "bankomat2.h"
#include "bankomat.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int moneyArray[] = {0, 0, 2, 4, 0, 0, 6, 9, 0, 0, 2, 0, 5, 10};
    Money * money = new Money(moneyArray);

    Bankomat1 * bankomat1 = new Bankomat1(moneyArray);
    bankomat1->GetMoney()->PrintToConsole();
    Bankomat2 * bankomat2 = new Bankomat2(money);
    bankomat2->GetMoney()->PrintToConsole();

    Bankomat * bankomat = new Bankomat(money);
    qDebug() << bankomat->GetMoney()->GetSum();
    bankomat->TakeMoney(money);
    int moneyArr1[] = {0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0};
    bankomat->PutMoney(new Money(moneyArr1));
    bankomat->GetMoney()->PrintToConsole();


    return a.exec();
}
