#ifndef POLYNOM_TNR_H
#define POLYNOM_TNR_H

#include <QDebug>
#include <iostream>


class Polynom_TNR
{
public:
    Polynom_TNR();
    Polynom_TNR(double a, double b, double c);

    double Calculate(double x) const;
    double Derivative(double x) const;
    double DefiniteIntegral(double start, double end) const;
    bool Solve(double &x1, double &x2);
    Polynom_TNR * operator+(const Polynom_TNR &polynom);
    Polynom_TNR * operator-(const Polynom_TNR &polynom);
    void SetPolynom(QString str);
    bool operator>(Polynom_TNR& pol);
    bool operator<(Polynom_TNR& pol);
    void SetPolynom(double a, double b, double c) { this->a = a; this->b = b; this->c = c; }
    friend std::ostream &operator<<(std::ostream& os, const Polynom_TNR& polynom);
    friend std::istream &operator>>(std::istream& os, Polynom_TNR& polynom);

    double GetA() { return a; }
    double GetB() { return b; }
    double GetC() { return c; }
    QString GetQPolynom() const;

    void PrintToConsole();


private:
    double IndefiniteIntegral(double x) const;
    double a = 1;
    double b = 0;
    double c = 0;

};

#endif // POLYNOM_TNR_H
