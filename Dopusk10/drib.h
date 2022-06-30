#ifndef DRIB_H
#define DRIB_H

#include <iostream>
#include <QString>
class Drib
{
public:
    Drib();
    Drib(int ch, int zn);
    friend std::string to_string(Drib& drib);
    friend QString to_qString(Drib& drib);
    bool operator==(const Drib& drib);
    Drib operator+(const Drib& drib);
    Drib operator-(const Drib& drib);
    void Reduce();


private:
    struct Lesson {
        std::string name;
        std::string date;
        int room;
        int group;
        std::string teacher;
    };
    Lesson lessons[100];
    int NOD(int ch, int zn);
    int ch = 0;
    int zn = 1;
};

#endif // DRIB_H
