
#include "cursor_tnr.h"

#include <iostream>

int main()
{  
    Cursor_TNR cur1 = Cursor_TNR();
    Cursor_TNR cur2 = Cursor_TNR(2, 5);
    Cursor_TNR cur3 = Cursor_TNR(cur1);

    Cursor_TNR::SetSize(1);
    cur1.SetSize(3);

    cur3 = cur1 + cur2;
    cur3 = cur1.operator+(cur2);

    std::cout << cur1;

}
