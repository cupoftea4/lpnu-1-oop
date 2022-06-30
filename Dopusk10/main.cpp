#include <QCoreApplication>
#include "set.h"
#include "drib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const int Size = 3;
    Set<Drib> * set1 = new Set<Drib>(Size);
    Set<Drib> * set2 = new Set<Drib>(Size);
    for (int i = 0; i < Size; i++) {
        set1->SetAt(i, Drib(i+2, i+Size));
    }
    for (int i = 0; i < Size; i++) {
        set2->SetAt(i, Drib(i+1, i+2));
    }
    set1->Print("Set 1");
    set2->Print("Set 2");
    Set<Drib> * res;
    res = *set1 - set2;
    res->Print("Subtraction");
    delete res;
    res = *set1 + set2;
    res->Print("Addition");
    delete res;
    res = set1->Intersection(set2);
    res->Print("Intersection");

    delete set1;
    delete set2;
    delete res;
    return a.exec();
}
