#include "RPN.hpp"

RPN::RPN( void ): _str("")
{}

RPN::RPN( std::string str ): _str(str)
{
    int i = 0;

    while (_str[i])
    {
        if (isdigit(_str[i]))
        {
            
        }
        else if (_str[i] == '+')
            this->add();
        else if (_str[i] == '-')
            this->sub();
        else if (_str[i] == '*')
            this->mul();
        else if (_str[i] == '/')
            this->div();
        i++;
    }
}

RPN::RPN( RPN & cpy )
{
    *this = cpy;
}

RPN::~RPN( void )
{}

RPN & RPN::operator=( RPN & asg )
{
    if (this != &asg)
    {
        this->_str = asg._str;
        this->_s = asg._s;
    }
    return *this;
}

int RPN::getRes( void ) const
{
    return this->_s.top();
}

void RPN::add( void )
{
    int a = this->_s.top();
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b + a);
}

void RPN::sub( void )
{
    int a = this->_s.top();
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b - a);
}

void RPN::mul( void )
{
    int a = this->_s.top();
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b * a);
}

void RPN::div( void )
{
    int a = this->_s.top();
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b / a);
}
