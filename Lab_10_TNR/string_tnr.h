#ifndef STRING_TNR_H
#define STRING_TNR_H

#include <string.h>
#include <qstring.h>
const int StringSize = 1000;

class String_TNR
{
public:
    String_TNR();
    String_TNR(QString  str);
    bool operator>(String_TNR& str);
    bool operator<(String_TNR& str);
    QString ToQString();
private:
    char string[StringSize];
};

#endif // STRING_TNR_H
