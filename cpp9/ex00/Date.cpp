#include "Date.hpp"

static bool isStringDigit(std::string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(str.c_str()[i]))
            return (false);
    }
    return (true);
} 

Date::Date( void ): year(0), month(0), day(0), isValid(0)
{}

Date::Date( std::string str ): year(0), month(0), day(0), isValid(0) //mes, dia año 0
{
    int pos;

    pos = str.find('-'); 
    this->year = std::atoi(str.c_str());
    if ((pos < 0) || (pos > 4) || (!isStringDigit(str, pos)))
        return ;
    str = str.substr(pos + 1);
    pos = str.find('-');
    this->month = std::atoi(str.c_str());
    if ((pos < 0) || (pos > 2) || (!isStringDigit(str, pos)) || (month > 12))
        return ;
    str = str.substr(pos + 1);
    this->day = std::atoi(str.c_str());
    if ((str.length() < 0) || (str.length() > 2) || (!isStringDigit(str, str.length())) || (day > 31)
        || ((month == 4) && (day > 30)) || ((month == 6) && (day > 30))
        || ((month == 9) && (day > 30)) || ((month == 11) && (day > 30))
        || ((year % 4 == 0) && (month == 2) && (day > 29)) || ((year % 4 != 0) && (month == 2) && (day > 28)))
        return ;
    this->isValid = 1;
}

Date::Date( Date & cpy )
{
    *this = cpy;
}

Date::~Date( void )
{}

bool Date::dateBefore( Date date )
{
    if ((this->year == date.year) && (this->year == date.year) && (this->year == date.year))
        return false;
    if (this->year < date.year)
        return false;
    if (this->month < date.month)
        return false;
    if (this->day < date.day)
        return false;
    return true;
}

Date & Date::operator=( Date & asg )
{
    if (this != &asg)
    {
        this->year = asg.year;
        this->month = asg.month;
        this->day = asg.day;
        this->isValid = asg.isValid;
    }
    return *this;
}
