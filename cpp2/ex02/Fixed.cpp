#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ): _f_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const num )
{
	std::cout << "Int constructor called" << std::endl;
	int n = num << this->_f_bits;
	this->_f_value = n;
}

Fixed::Fixed( float const num )
{
	std::cout << "Float constructor called" << std::endl;
	this->_f_value = roundf(num * (1 << this->_f_bits));
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_f_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_f_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_f_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_f_value / (float)(1 << this->_f_bits));
} 

int Fixed::toInt( void ) const
{
	return this->_f_value >> this->_f_bits;
} 

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

bool Fixed::operator<( Fixed const & rhs)
{
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>( Fixed const & rhs)
{
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=( Fixed const & rhs)
{
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=( Fixed const & rhs)
{
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==( Fixed const & rhs)
{
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=( Fixed const & rhs)
{
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
}

float Fixed::operator+( Fixed const & rhs)
{
	return (this->toFloat() + rhs.toFloat());
}

float Fixed::operator-( Fixed const & rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

float Fixed::operator*( Fixed const & rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

float Fixed::operator/( Fixed const & rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++( )
{
	this->_f_value++;
	return *this;
}

Fixed & Fixed::operator++( int )
{
	return *this;
}

Fixed & Fixed::operator--( )
{
	this->_f_value--;
	return *this;
}

Fixed & Fixed::operator--( int )
{
	return *this;
}

const Fixed & Fixed::operatormin( Fixed const &rhs)
{
	if (this->getRawBits() < rhs.getRawBits())
		return *this;
	return rhs;
}

/*Fixed & Fixed::min( Fixed & a, Fixed & b )
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed & Fixed::max( Fixed & a, Fixed & b )
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}*/
