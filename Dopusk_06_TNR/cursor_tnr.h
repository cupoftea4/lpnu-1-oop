#ifndef CURSOR_TNR_H
#define CURSOR_TNR_H

#include <string>
#include <iostream>
using namespace std;

class Cursor_TNR
{
public:
    Cursor_TNR();
    Cursor_TNR(int x, int y);
    Cursor_TNR(Cursor_TNR &cursor);
    int GetX();
    int GetY();
    static int GetSize();
    string GetLook();
    void SetCoordinates(int x, int y);
    static void SetSize(int size);
    void SetLook(string url);
    Cursor_TNR operator+(const Cursor_TNR& cursor);
    friend ostream& operator<<(ostream& os, const Cursor_TNR& cursor);
    friend istream& operator>>(std::istream& os, Cursor_TNR& cursor);
private:
    int x = 0;
    int y = 0;
    static int size;
    string look = "~Desktop/look1.png";

};

#endif // CURSOR_TNR_H
