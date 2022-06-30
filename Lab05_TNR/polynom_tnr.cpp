#include "polynom_tnr.h"

Polynom::Polynom() { }

Polynom::Polynom(double a, double b, double c) : a(a), b(b), c(c) { }


QString Polynom::GetQPolynom() const
{
    return QString().asprintf("%gx^2%+gx%+g", a, b, c);
}

void Polynom::PrintToConsole()
{
    qDebug() << GetQPolynom();
}

std::ostream &operator<<(std::ostream& os, const Polynom& polynom) {
    os << polynom.GetQPolynom().toStdString();
    return os;
}

std::istream &operator>>(std::istream& os, Polynom& polynom) {
    os >> polynom.a;
    os >> polynom.b;
    os >> polynom.c;
    return os;
}

double Polynom::Calculate(double x) const
{
    return a*x*x + b*x + c;
}

double Polynom::Derivative(double x) const
{
    return 2*a*x + b;
}

double Polynom::DefiniteIntegral(double start, double end) const
{
    return IndefiniteIntegral(start) - IndefiniteIntegral(end);
}

bool Polynom::Solve(double &x1, double &x2)
{
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return false;
    x1 = (-b - sqrt(discriminant)) / (2 * a);
    x2 = (-b + sqrt(discriminant)) / (2 * a);
    return true;
}

Polynom *Polynom::operator+(const Polynom &polynom)
{
    double newA = this->a + polynom.a;
    double newB = this->b + polynom.b;
    double newC = this->c + polynom.c;
    Polynom * result = new Polynom(newA, newB, newC);
    return result;
}

Polynom *Polynom::operator-(const Polynom &polynom)
{
    double newA = this->a - polynom.a;
    double newB = this->b - polynom.b;
    double newC = this->c - polynom.c;
    Polynom * result = new Polynom(newA, newB, newC);
    return result;
}

double Polynom::IndefiniteIntegral(double x) const
{
    return a*x*x*x/3 + b*x*x/2 + c*x;
}
