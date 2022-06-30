#ifndef POLYNOM_TNR_H
#define POLYNOM_TNR_H

#include <QDebug>
#include <iostream>


class Polynom_TNR
{
public:
    Polynom_TNR();
    Polynom_TNR(double a, double b, double c);
    ~Polynom_TNR();

    Polynom_TNR * operator+(const Polynom_TNR &polynom);
    Polynom_TNR * operator-(const Polynom_TNR &polynom);
    Polynom_TNR * operator!();
    Polynom_TNR operator>(Polynom_TNR p1) {
        return p1;
    };

    double operator()(double x);
    double operator[](int i); // make friend
    friend bool operator==(Polynom_TNR &p1, Polynom_TNR &p2);
    friend std::ostream &operator<<(std::ostream& os, const Polynom_TNR& polynom);
    friend std::istream &operator>>(std::istream& os, Polynom_TNR& polynom);

    void SetPolynom(double a, double b, double c) { this->a = a; this->b = b; this->c = c; }
    double GetA() { return a; }
    double GetB() { return b; }
    double GetC() { return c; }
    QString GetQPolynom();
    static int GetPolynomsCount() { return polynomsCount; }

    void PrintToConsole();
    bool Solve(double &x1, double &x2);
    double Calculate(double x) const;
    double Derivative(double x) const;
    double DefiniteIntegral(double start, double end) const;
    friend Polynom_TNR *Multiply(Polynom_TNR &polynom, double coeff);


private:
    static int polynomsCount;
    double IndefiniteIntegral(double x) const;
    double a = 1;
    double b = 0;
    double c = 0;

};

#endif // POLYNOM_TNR_H
