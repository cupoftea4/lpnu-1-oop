#include "string_tnr.h"

String_TNR::String_TNR()
{}

String_TNR::String_TNR(QString str)
{
    strcpy(string, str.toStdString().c_str());
}

bool String_TNR::operator>(String_TNR &str)
{
    if (strcmp(this->string, str.string) > 0) return true;
    return false;
}

bool String_TNR::operator<(String_TNR &str)
{
    if (strcmp(this->string, str.string) < 0) return true;
    return false;
}

QString String_TNR::ToQString()
{
    return QString::fromStdString(string);
}
