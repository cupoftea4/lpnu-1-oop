#include "polynom_tnr.h"

Polynom_TNR::Polynom_TNR() { polynomsCount++; }

Polynom_TNR::Polynom_TNR(double a, double b, double c) : a(a), b(b), c(c) { polynomsCount++; }

Polynom_TNR::~Polynom_TNR()
{
    polynomsCount--;
}

int Polynom_TNR::polynomsCount = 0;

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

Polynom_TNR *Multiply(Polynom_TNR &polynom, double coeff) {
    polynom.a = polynom.a * coeff;
    polynom.b = polynom.b * coeff;
    polynom.c = polynom.c * coeff;
    return &polynom;
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

Polynom_TNR *Polynom_TNR::operator!()
{
    a = -a;
    b = -b;
    c = -c;
    return this;
}

double Polynom_TNR::operator()(double x)
{
    return Calculate(x);
}

double Polynom_TNR::operator[](int index)
{
    if (index < 0 || index > 2) qDebug() << "Wrong polynom index";
    switch (index) {
        case 1:
            return a;
        case 2:
            return b;
        case 3:
            return c;
        default:
            return a;
    }

}

bool operator==(Polynom_TNR &p1, Polynom_TNR &p2) {
//    qDebug() << p1.a << " " << p2.a;
    return ((p1.a == p2.a) && (p1.b == p2.b) && (p1.c == p2.c));
}

double Polynom_TNR::IndefiniteIntegral(double x) const
{
    return a*x*x*x/3 + b*x*x/2 + c*x;
}
