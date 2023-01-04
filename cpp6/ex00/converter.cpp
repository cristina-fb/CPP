/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:03:05 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/04 18:00:32 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

bool isInt(std::string str)
{
    unsigned long i;
    for (i = 0; i < str.length(); i++)
        if (!std::isspace(str[i]))
            break;
    std::cout << i << " " << str.length() << std::endl;
    if (i >= str.length())
        return false;
    if ((str[i] == '+') || (str[i] == '-'))
        i++;
    if (i >= str.length())
        return false;
    for (unsigned long j = i; j < str.length(); j++)
        if (!isdigit(str[j]))
            return false;
    return true;
}

bool isDouble(std::string str)
{
    unsigned long i, j;
    int dot = 0;
    for (i = 0; i < str.length(); i++)
        if (!std::isspace(str[i]))
            break;
    if (i >= str.length())
        return false;
    if ((str[i] == '+') || (str[i] == '-'))
        i++;
    if (i >= str.length())
        return false;
    for (j = i; j < str.length(); j++)
    {
        if (!isdigit(str[j]) && (str[j] != '.'))
            return false;
        if (str[j] == '.')
            dot++;
        if ((j == str.length() - 1) && (!isdigit(str[j])))
            return false;
    }
    if ((dot != 1))
        return false;
    return true;
}

bool isFloat(std::string str)
{
    unsigned long i, j;
    int dot = 0;
    for (i = 0; i < str.length(); i++)
        if (!std::isspace(str[i]))
            break;
    if (i >= str.length())
        return false;
    if ((str[i] == '+') || (str[i] == '-'))
        i++;
    if (i >= str.length())
        return false;
    for (j = i; j < str.length() - 1; j++)
    {
        if (!isdigit(str[j]) && (str[j] != '.'))
            return false;
        if (str[j] == '.')
            dot++;
        if ((j == str.length() - 2) && (!isdigit(str[j])))
            return false;
    }
    if (dot != 1)
        return false;
    return true;
}

Converter::Converter( void ): _type(-1), _c(0), _i(0), _f(0.0f), _d(0.0)
{}

Converter::Converter( std::string str ): _type(-1), _c(0), _i(0), _f(0.0f), _d(0.0)
{
    std::stringstream o;
    
    if ((str.length() == 1) && !isdigit(str[0]))
    {
        this->_c = str[0];
        this->_type = 0;
        return;
    }
    if ((str == "-inff") || (str == "+inff") || (str == "inff") || (str == "nanf") || (str == "45.6") || isFloat(str))
    {
        o << str;
        o >> this->_f;
        this->_type = 2;
        return;
    }
    if ((str == "-inf") || (str == "+inf") || (str == "inf") || (str == "nan") || isDouble(str))
    {
        o << str;
        o >> this->_d;
        this->_type = 3;
        return;
    }
    if (isInt(str))
    {
        o << str;
        o >> this->_i; 
        this->_type = 1;
        return ;
    }
}

Converter::Converter( Converter & cpy )
{
    *this = cpy;
}

Converter::~Converter ( void )
{}

Converter & Converter::operator=( Converter & asg )
{
    if (this != &asg )
    {
        this->_type = asg.getType();
        this->_c = asg.getC();
        this->_i = asg.getI();
        this->_f = asg.getF();
        this->_d = asg.getD();
    }
    return *this;
}

void Converter::convert( void )
{
    switch(this->_type)
    {
        case 0:
        {
            this->_i = static_cast<int>(this->_c);
            this->_f = static_cast<float>(this->_c);
            this->_d = static_cast<double>(this->_c);
            return;
        }
        case 1:
        {
            this->_c = static_cast<char>(this->_i);
            this->_f = static_cast<float>(this->_i);
            this->_d = static_cast<double>(this->_i);
            return;
        }
        case 2:
        {
            this->_c = static_cast<char>(this->_f);
            this->_i = static_cast<int>(this->_f);
            this->_d = static_cast<double>(this->_f);
            return;
        }
        case 3:
        {
            this->_c = static_cast<char>(this->_d);
            this->_i = static_cast<int>(this->_d);
            this->_f = static_cast<float>(this->_d);
            return;
        }
    }
}

int Converter::getType( void ) const
{
    return this->_type;
}

char Converter::getC( void ) const
{
    return this->_c;
}

int Converter::getI( void ) const
{
    return this->_i;
}

float Converter::getF( void ) const
{
    return this->_f;
}

double Converter::getD( void ) const
{
    return this->_d;
}
std::ostream & operator<<( std::ostream & o, Converter & rhs)
{
    if (rhs.getType() == -1)
    {
        std::cout << "Not a valid literal" << std::endl;
        return o;
    }
    if ((rhs.getType() == 0) || (rhs.getType() == 1))
    {
        std::cout << std::fixed << std::setprecision(1);
    }
    std::cout << "char: ";
    if (isprint(rhs.getC()))
    { 
        std::cout << "'" << rhs.getC() << "'" << std::endl;
    }
    else
    {
        std::cout << "Non displayable" << std::endl;
    }
	std::cout << "int: " << rhs.getI() << std::endl;
	std::cout << "float: " << rhs.getF() << "f" << std::endl;
	std::cout << "double: " << rhs.getD() << std::endl;
    return o;
}
