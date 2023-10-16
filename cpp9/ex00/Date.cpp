/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:05:38 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 17:18:28 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Date::Date( std::string str ): year(0), month(0), day(0), isValid(0), dstr(str)
{
    int pos;
    pos = str.find('-'); 
    this->year = std::atoi(str.c_str());
    if ((pos < 0) || (!isStringDigit(str, pos)))
        return ;
    str = str.substr(pos + 1);
    pos = str.find('-');
    this->month = std::atoi(str.c_str());
    if ((pos < 0) || (!isStringDigit(str, pos)) || (month > 12) || (month < 1))
        return ;
    str = str.substr(pos + 1);
    this->day = std::atoi(str.c_str());
    if ((str.length() < 0) || (!isStringDigit(str, str.length())) || (day > 31) || (day < 1)
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

Date & Date::operator=( Date & asg )
{
    if (this != &asg)
    {
        this->year = asg.year;
        this->month = asg.month;
        this->day = asg.day;
        this->isValid = asg.isValid;
        this->dstr = asg.dstr;
    }
    return *this;
}
