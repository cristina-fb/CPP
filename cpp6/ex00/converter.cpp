/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:03:05 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/05 15:30:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter( void ): _str(""), _type(-1), _c(0), _i(0), _f(0.0f), _d(0.0)
{}

Converter::Converter( std::string str ): _str(str), _type(-1), _c(0), _i(0), _f(0.0f), _d(0.0)
{
    std::stringstream o;

    if ((this->_str == "inff") || (this->_str == "-inff") || (this->_str == "+inff"))
    {
        std::cout << "*** FORM FLOAT ***" << std::endl;
        this->_str = this->_str.substr(0, this->_str.length() - 1);
        o << this->_str;
        o >> this->_d;
        this->_type = 3;
        this->convert();
        return ;
    }
    if ((this->_str == "inf") || (this->_str == "-inf") || (this->_str == "+inf"))
    {
        std::cout << "*** FORM DOUBLE ***" << std::endl;
        o << this->_str;
        o >> this->_d;
        this->_type = 3;
        this->convert();
        return ;
    } 
    if ((this->_str.length() == 1) && !isdigit(this->_str[0]))
    {
        std::cout << "*** FORM CHAR ***" << std::endl;
        this->_c = this->_str[0];
        this->_type = 0;
        this->convert();
        return;
    }
    if (this->_str.find('.') == std::string::npos)
    {
        std::cout << "*** FORM INT ***" << std::endl;
        o << this->_str;
        o >> this->_i;
        if(!o.fail())
        {
            this->_type = 1;
            this->convert();
            return ;
        }
    }
    if ((this->_str[this->_str.length() - 1] == 'f') || o.fail())
    {
        std::cout << "*** FORM FLOAT ***" << std::endl;
        if (this->_str[this->_str.length() - 1] == 'f')
            this->_str = this->_str.substr(0, this->_str.length() - 1);
        o << this->_str;
        o >> this->_f;
        if(!o.fail())
        {
            this->_type = 2;
            this->convert();
            return ;
        }
    }
    std::cout << "*** FORM DOUBLE ***" << std::endl;
    o << this->_str;
    o >> this->_d;
    if(!o.fail())
    {
        this->_type = 3;
        this->convert();
        return ;
    }
    this->convert();
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
        this->_str = asg.getStr();
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

std::string Converter::getStr( void ) const
{
    return this->_str;
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
        //todo imposible
    }
    if ((rhs.getStr() == "nan") || (rhs.getStr() == "nanf") || (rhs.getStr() == "inf") || (rhs.getStr() == "inff") ||
        (rhs.getStr() == "+inf") || (rhs.getStr() == "+inff") || (rhs.getStr() == "-inf") || (rhs.getStr() == "-inff"))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if ((rhs.getType() == 0) || (rhs.getType() == 1))
            std::cout << std::fixed << std::setprecision(1);
        std::cout << "char: ";
        if (isprint(rhs.getC()))
            std::cout << "'" << rhs.getC() << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: " << rhs.getI() << std::endl;
    }
	std::cout << "float: " << rhs.getF() << "f" << std::endl;
	std::cout << "double: " << rhs.getD() << std::endl;
    return o;
}
