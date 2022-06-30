#include "goods.h"

int Goods::goodsCount = 0;

Goods::Goods(){ goodsCount++; }

Goods::Goods(string name, Money * price, string date, int count, int invoiceID)
{
    *this->count = count;
    *this->date = date;
    *this->invoiceID = invoiceID;
    *this->name = name;
    this->price = price;
    goodsCount++;
}

Goods::Goods(Goods &goods)
{
    *count = *goods.count;
    *date = *goods.date;
    *invoiceID = *goods.invoiceID;
    *name = *goods.name;
    if (goods.price != nullptr) {
        *price = *goods.price;
    } else {
        price = nullptr;
    }
    goodsCount++;
}

void Goods::UpdateCount(int diff)
{
    *count += diff;
}

void Goods::SetPrice(Money * price)
{
    this->price = price;
}

double Goods::GetValue()
{
    return price->GetValue() * (*count);
}

string Goods::print()
{
    return "Name: " + *name + "\nPrice" + price->print() + "\nDate: " + *date
            + "\nCount: " + std::to_string(*count) + "\nInvoice: " + std::to_string(*invoiceID);
}

int Goods::GetGoodsCount()
{
    return goodsCount;
}

Goods::~Goods()
{
    goodsCount--;
    delete count;
    delete date;
    delete invoiceID;
    delete name;
    delete price;
}
