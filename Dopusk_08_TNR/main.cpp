#include <QCoreApplication>
#include <money.h>
#include <goods.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Money * bookPrice = new Money(123, 23);
    Money * puzzlePrice = new Money(200, 0);
    Money * chairPrice = new Money(1220, 50);

    Goods * goods1 = new Goods("Книга", bookPrice, "04.02.2001", 5, 1);
    Goods * goods2 = new Goods("Пазли", puzzlePrice, "09.01.2020", 15, 1);
    Goods * goods3 = new Goods("Крісло", chairPrice, "21.11.2019", 23, 1);

    goods1->GetGoodsCount();
    Goods::GetGoodsCount();

    goods1->print();
    goods2->print();
    goods3->print();

    delete goods1;
    delete goods2;
    delete goods3;
    return a.exec();
}
