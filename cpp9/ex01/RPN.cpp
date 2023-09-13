#include "RPN.hpp"

RPN::RPN( void ): _str("")
{}

RPN::RPN( std::string str ): _str(str)
{
    int i = 0;
    int n = 0;

    if (_str.empty())
            throw("Error");
    while (_str[i])
    {
        if (isdigit(_str[i]))
        {
            if (++n >= 10)
                throw("Error");
            this->_s.push(std::atol(&_str[i]));
            if (this->_s.top() > 2147483647)
                throw("Error");
            while (isdigit(_str[i]))
                i++;
            continue ;
        }
        else if (_str[i] == '+')
            this->add();
        else if (_str[i] == '-')
            this->sub();
        else if (_str[i] == '*')
            this->mul();
        else if (_str[i] == '/')
            this->div();
        else if (!isspace(str[i]))
            throw("Error");
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
    if (sum > 2147483647)
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
    if (sub < -2147483648)
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
    if (mul > 2147483647)
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
