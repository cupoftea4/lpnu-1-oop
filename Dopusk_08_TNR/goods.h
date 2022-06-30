#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <money.h>
using std::string;

class Goods
{
public:
    Goods();
    Goods(string name, Money * price, string date, int count, int invoiceID);
    Goods(Goods &goods);
    ~Goods();
    void UpdateCount(int diff);
    void SetPrice(Money * price);
    double GetValue();
    string print();

    static int GetGoodsCount();
private:
    Money * price = nullptr;
    string * name = new string();
    string * date = new string();
    int * count = new int();
    int * invoiceID = new int();
    static int goodsCount;

};

#endif // GOODS_H
