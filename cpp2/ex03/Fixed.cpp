#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ): _f_value(0){}

Fixed::Fixed( int const num )
{
	int n = num << this->_f_bits;
	this->_f_value = n;
}

Fixed::Fixed( float const num ){ this->_f_value = roundf(num * (1 << this->_f_bits)); }

Fixed::Fixed( Fixed const & src ){ *this = src; }

Fixed::~Fixed( void ){}

int Fixed::getRawBits( void ) const { return this->_f_value; }

void Fixed::setRawBits( int const raw ) { this->_f_value = raw; }

float Fixed::toFloat( void ) const { return ((float)this->_f_value / (float)(1 << this->_f_bits)); } 

int Fixed::toInt( void ) const { return this->_f_value >> this->_f_bits; }

Fixed & Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
	{
		this->_f_value = rhs.getRawBits();
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

bool Fixed::operator<( Fixed const & rhs){ return (this->getRawBits() < rhs.getRawBits()); }

bool Fixed::operator>( Fixed const & rhs){ return (this->getRawBits() > rhs.getRawBits()); }

bool Fixed::operator<=( Fixed const & rhs){ return (this->getRawBits() <= rhs.getRawBits()); }

bool Fixed::operator>=( Fixed const & rhs){ return (this->getRawBits() >= rhs.getRawBits()); }

bool Fixed::operator==( Fixed const & rhs){ return (this->getRawBits() == rhs.getRawBits()); }

bool Fixed::operator!=( Fixed const & rhs){ return (this->getRawBits() != rhs.getRawBits()); }

float Fixed::operator+( Fixed const & rhs){ return (this->toFloat() + rhs.toFloat()); }

float Fixed::operator-( Fixed const & rhs){ return (this->toFloat() - rhs.toFloat()); }

float Fixed::operator*( Fixed const & rhs){ return (this->toFloat() * rhs.toFloat()); }

float Fixed::operator/( Fixed const & rhs){ return (this->toFloat() / rhs.toFloat()); }

float Fixed::operator++( int )
{
	float n = toFloat();
	this->_f_value++;
	return n;
}

Fixed & Fixed::operator++( )
{
	this->_f_value++;
	return *this;
}

float Fixed::operator--( int )
{
	float n = toFloat();
	this->_f_value--;
	return n;
}

Fixed & Fixed::operator--( )
{
	this->_f_value--;
	return *this;
}

Fixed & Fixed::min( Fixed & a, Fixed & b )
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
}

const Fixed & Fixed::min( Fixed const & a, Fixed const & b )
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed & Fixed::max( Fixed const & a, Fixed const & b )
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
