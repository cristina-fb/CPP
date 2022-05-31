#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ): _x(Fixed()), _y(Fixed()){}

Point::Point( Point & src ): _x(src.getX()), _y(src.getY()) {}

Point::Point( Fixed const x, Fixed const y): _x(x), _y(y){}

Point::~Point( void ){}

Point & Point::operator=( Point & rhs )
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(this->_x) = rhs.getX();
		const_cast<Fixed&>(this->_y) = rhs.getY();
	}
	return *this;
}

Fixed const & Point::getX( void ) const { return this->_x; }

Fixed const & Point::getY( void ) const { return this->_y; }
