/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:03:05 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 18:02:53 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter( void ): _type(-1), _c(0), _i(0), _f(0.0f), _d(0.0)
{}

Converter::Converter( std::string str ): _type(-1), _c(0), _i(0), _f(0.0f), _d(0.0)
{
    bool flag = false;
    char *end;
    if ((str.length() == 1) && ((str[0] < '0') || (str[0] > '9')))
    {
        this->_type = 0;
        this->_c = str[0];
        return;
    }
    if ((str == "-inff") || (str == "+inff") || (str == "inff") || (str == "nanf"))
    {
        this->_type = 2;
        this->_f = strtof(&str, &end);
        return;
    }
    if ((str == "-inf") || (str == "+inf") || (str == "inf") || (str == "nan"))
    {
        this->_type = 3;
        this->_d = strtod(&str, &end);
        return;
    }
    /*for (int i = 0; i < str.length(); i++)
    {
    }*/
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
    std::cout << "char: '" << rhs.getC() << "'" << std::endl;
	std::cout << "int: " << rhs.getI() << std::endl;
	std::cout << "float: " << rhs.getF() << "f" << std::endl;
	std::cout << "double: " << rhs.getD() <<std::endl;
    return o;
}
