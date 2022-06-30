#include "drib.h"

Drib::Drib()
{

}

Drib::Drib(int ch, int zn)
{
    this->ch = ch;
    this->zn = zn;
}

bool Drib::operator==(const Drib &drib)
{
    return this->zn == drib.zn && this->ch == drib.ch;
}

Drib Drib::operator+(const Drib &drib)
{
    Drib res;
    int lcm = (zn > drib.zn) ? zn : drib.zn;
        do
        {
            if (lcm % zn == 0 && lcm % drib.zn == 0)
            {
                res.zn = lcm;
                break;
            }
            else
                ++lcm;
        } while (true);
    res.ch = ch * (lcm / zn) + drib.ch * (lcm / drib.zn);
    res.Reduce();
    return res;
}

Drib Drib::operator-(const Drib &drib)
{
    Drib res;
    int lcm = (zn > drib.zn) ? zn : drib.zn;
    do {
        if (lcm % zn == 0 && lcm % drib.zn == 0) {
            res.zn = lcm;
            break;
        }
        else
            ++lcm;
    } while (true);
    res.ch = ch * (lcm / zn) - drib.ch * (lcm / drib.zn);
    res.Reduce();
    return res;
}

void Drib::Reduce()
{
    int nod = NOD(ch, zn);
    ch/=nod;
    zn/=nod;
}


int Drib::NOD(int vl, int v2) {
    while (v2)
    {
        int temp=v2;
        v2=vl%v2;
        vl=temp;
    }
    return vl;
}

std::string to_string(Drib& drib) {
    return std::to_string(drib.ch) + "/" + std::to_string(drib.zn);
}

QString to_qString(Drib& drib) {
    return QString::number(drib.ch) + "/" + QString::number(drib.zn);
}



