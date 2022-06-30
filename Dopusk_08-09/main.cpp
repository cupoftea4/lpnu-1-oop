#include <QCoreApplication>

#include "vipdeposit.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Deposit * depos[3];
    OneOffDeposit * dep1 = new OneOffDeposit("amy", 100, 3);
    TermDeposit * dep2 = new TermDeposit("dep2", 200, 2);
    VipDeposit * dep3 = new VipDeposit("viip", 1000, 10);

    depos[0] = dep1;
    depos[1] = dep2;
    depos[2] = dep3;

    depos[0]->GetProfit(); // перевизначений

    VipDeposit * dep4 = dynamic_cast<VipDeposit *>(depos[2]);
    depos[2]->UpdateProfile("username", "paaass");
    dep4->UpdateProfile(100); // перевантажений

    depos[1]->GetProfit(); // перевизначений

    delete dep1;
    dep1 = nullptr;
    delete dep2;
    dep2 = nullptr;
    delete dep3;
    dep3 = nullptr;

    return a.exec();
}
