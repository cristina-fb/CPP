#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ): _x(Fixed()), _y(Fixed()){}

Point::Point( Point const & src ){ /* *this = src;*/}

Point::Point( Fixed const x, Fixed const y): _x(x), _y(y){}

Point::~Point( void ){}

Point & Point::operator=( Point & rhs )
{
	if(this != &rhs)
	{
		//this->_x = rhs.getX();
		//this->_y = rhs.getY();
	}
	return *this;
}

const Fixed & Point::getX( void ) { return this->_x; }

const Fixed & Point::getY( void ) { return this->_y; }
