#include "RPN.hpp"

RPN::RPN( void ): _str("")
{}

RPN::RPN( std::string str ): _str(str)
{
    std::stringstream o;
    int i = 0;
    int n = 0;
    int num;

    while (_str[i])
    {
        if (isdigit(_str[i]))
        {
            n++;
            if (n >= 10)
                throw("Error A");
            o << &_str[i];
            o >> num;
            o.clear();
            o.str("");
            this->_s.push(num);
            while (isdigit(_str[i]))
                i++;
            i--;
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
            throw("Error B");
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
        this->_str = asg.getStr();
        //copy de las stack
    }
    return *this;
}

std::string RPN::getStr( void ) const
{
    return this->_str;
}

int RPN::getRes( void ) const
{
    if (this->_s.size() != 1)
        throw("Error C");
    return this->_s.top();
}

void RPN::add( void )
{
    if (this->_s.size() < 2)
        throw("Error D");
    int a = this->_s.top();
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b + a);
}

void RPN::sub( void )
{
    if (this->_s.size() < 2)
        throw("Error E");
    int a = this->_s.top();
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b - a);
}

void RPN::mul( void )
{
    if (this->_s.size() < 2)
        throw("Error F");
    int a = this->_s.top();
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b * a);
}

void RPN::div( void )
{
    if (this->_s.size() < 2)
        throw("Error G");
    int a = this->_s.top();
    if (a == 0)
        throw("Error H");
    this->_s.pop();
    int b = this->_s.top();
    this->_s.pop();
    this->_s.push(b / a);
}
