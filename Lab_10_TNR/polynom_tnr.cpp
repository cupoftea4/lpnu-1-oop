#include "polynom_tnr.h"

Polynom_TNR::Polynom_TNR() { }

Polynom_TNR::Polynom_TNR(double a, double b, double c) : a(a), b(b), c(c) { }


QString Polynom_TNR::GetQPolynom() const
{
    return QString().asprintf("%gx^2%+gx%+g", a, b, c);
}

void Polynom_TNR::PrintToConsole()
{
    qDebug() << GetQPolynom();
}

std::ostream &operator<<(std::ostream& os, const Polynom_TNR& polynom) {
    os << polynom.GetQPolynom().toStdString();
    return os;
}

std::istream &operator>>(std::istream& os, Polynom_TNR& polynom) {
    os >> polynom.a;
    os >> polynom.b;
    os >> polynom.c;
    return os;
}

double Polynom_TNR::Calculate(double x) const
{
    return a*x*x + b*x + c;
}

double Polynom_TNR::Derivative(double x) const
{
    return 2*a*x + b;
}

double Polynom_TNR::DefiniteIntegral(double start, double end) const
{
    return IndefiniteIntegral(start) - IndefiniteIntegral(end);
}

bool Polynom_TNR::Solve(double &x1, double &x2)
{
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return false;
    x1 = (-b - sqrt(discriminant)) / (2 * a);
    x2 = (-b + sqrt(discriminant)) / (2 * a);
    return true;
}

Polynom_TNR *Polynom_TNR::operator+(const Polynom_TNR &polynom)
{
    double newA = this->a + polynom.a;
    double newB = this->b + polynom.b;
    double newC = this->c + polynom.c;
    Polynom_TNR * result = new Polynom_TNR(newA, newB, newC);
    return result;
}

Polynom_TNR *Polynom_TNR::operator-(const Polynom_TNR &polynom)
{
    double newA = this->a - polynom.a;
    double newB = this->b - polynom.b;
    double newC = this->c - polynom.c;
    Polynom_TNR * result = new Polynom_TNR(newA, newB, newC);
    return result;
}

void Polynom_TNR::SetPolynom(QString str)
{
    QStringList list = str.split(QLatin1Char(','), Qt::SkipEmptyParts);
    if (list.length() == 3) {
        a = list[0].toDouble();
        b = list[1].toDouble();
        c = list[2].toDouble();
    } else {
        list = str.split(QLatin1Char(' '), Qt::SkipEmptyParts);
        if (list.length() == 3) {
            a = list[0].toDouble();
            b = list[1].toDouble();
            c = list[2].toDouble();
        }
    }

}

bool Polynom_TNR::operator>(Polynom_TNR &pol)
{
    return a > pol.a;
}

bool Polynom_TNR::operator<(Polynom_TNR &pol)
{
    return a < pol.a;
}

double Polynom_TNR::IndefiniteIntegral(double x) const
{
    return a*x*x*x/3 + b*x*x/2 + c*x;
}
