/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:25 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 11:54:25 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void )
{}

RPN::RPN( std::string const &str ): _str(str)
{
    unsigned long int i = 0;

    if (_str.empty())
            throw("Error");
    while (_str[i])
    {
        if (isdigit(_str[i]))
        {
            if ((i > 0) && (_str[i - 1] == '-'))
                this->_s.push(std::atol(&_str[i - 1]));
            else
                this->_s.push(std::atol(&_str[i]));
            if ((this->_s.top() > INT_MAX) || (this->_s.top() < INT_MIN))
                throw("Error");
            while (isdigit(_str[i]))
                i++;
            continue ;
        }
        else if (_str[i] == '+')
            this->add();
        else if (_str[i] == '-')
        {
            if ((i < _str.length() - 1) && (isdigit(_str[i + 1])))
            {
                i++;
                continue;
            }
            this->sub();
        }
        else if (_str[i] == '*')
            this->mul();
        else if (_str[i] == '/')
            this->div();
        else if (!isspace(str[i]))
            throw("Error");
        i++;
    }
}

RPN::RPN( RPN const &cpy )
{
    *this = cpy;
}

RPN::~RPN( void )
{}

RPN & RPN::operator=( RPN const &asg )
{
    std::stack<long int> aux = asg.getStack();

    if (this != &asg)
    {
        this->_str = asg.getStr();
        while (!this->_s.empty())
            this->_s.pop();
        this->_s = aux;
    }
    return *this;
}

std::string RPN::getStr( void ) const
{
    return this->_str;
}

std::stack<long int> RPN::getStack( void ) const
{
    return this->_s;
}

int RPN::getRes( void ) const
{
    if (this->_s.size() != 1)
        throw("Error");
    return this->_s.top();
}

void RPN::add( void )
{
    long int    sum;

    if (this->_s.size() < 2)
        throw("Error");
    long int a = this->_s.top();
    this->_s.pop();
    long int b = this->_s.top();
    this->_s.pop();
    sum = b + a;
    if ((sum > INT_MAX) || (sum < INT_MIN))
        throw("Error");
    this->_s.push(sum);
}

void RPN::sub( void )
{
    long int sub;

    if (this->_s.size() < 2)
        throw("Error");
    long int a = this->_s.top();
    this->_s.pop();
    long int b = this->_s.top();
    this->_s.pop();
    sub = b - a;
    if ((sub > INT_MAX) || (sub < INT_MIN))
        throw("Error");
    this->_s.push(sub);
}

void RPN::mul( void )
{
    long int mul;

    if (this->_s.size() < 2)
        throw("Error");
    long int a = this->_s.top();
    this->_s.pop();
    long int b = this->_s.top();
    this->_s.pop();
    mul = b * a;
    if ((mul > INT_MAX) || (mul < INT_MIN))
        throw("Error");
    this->_s.push(mul);
}

void RPN::div( void )
{
    if (this->_s.size() < 2)
        throw("Error");
    long int a = this->_s.top();
    if (a == 0)
        throw("Error");
    this->_s.pop();
    long int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b / a);
}
