#include "cursor_tnr.h"

int Cursor_TNR::size = 1;

Cursor_TNR::Cursor_TNR() {}

Cursor_TNR::Cursor_TNR(int x, int y) {
    SetCoordinates(x, y);
}

Cursor_TNR::Cursor_TNR(Cursor_TNR &cursor)
{
    x = cursor.GetX();
    y = cursor.GetY();
    size = cursor.GetSize();
    look = cursor.GetLook();
}

int Cursor_TNR::GetX()
{
    return x;
}

int Cursor_TNR::GetY()
{
    return y;
}

int Cursor_TNR::GetSize()
{
    return size;
}

string Cursor_TNR::GetLook()
{
    return look;
}

void Cursor_TNR::SetCoordinates(int x, int y)
{
    if (x >= 1 && y >= 1) {
        this->x = x;
        this->y = y;
    }
}

void Cursor_TNR::SetSize(int size)
{
    if (size >= 1 && size <= 15) {
        Cursor_TNR::size = size;
    }
}

void Cursor_TNR::SetLook(string url)
{
    this->look = url;
}

Cursor_TNR Cursor_TNR::operator+(const Cursor_TNR &cur)
{
    Cursor_TNR result(this->x + cur.x, this->y + cur.y);
    return result;
}


ostream& operator<<(ostream& os, const Cursor_TNR& cursor) {
    os << "Size: " << cursor.size << "\nCoordinats:" << cursor.x << ", " << cursor.y << "Look: " << cursor.look;
    return os;
};

istream& operator>>(std::istream& os, Cursor_TNR& cursor) {
    os >> cursor.x;
    os >> cursor.y;
    return os;
}
