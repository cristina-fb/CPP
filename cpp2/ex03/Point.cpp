#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ): _x(Fixed()), _y(Fixed())
{
	std::cout << "Default Constructor Called" << std::endl;
}

Point::Point( Point const & src ):
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = src;
}

Fixed::Point( Fixed const x, Fixed const y): _x(x), _y(y)
{
	std::cout << "Fixed Point Constructor Called" << std::endl;
}

Point::~Point( void ):
{
	std::cout << "Destructor Called" << std::endl;
}

Point & Point::operator=( Point & rhs ):
{
	if(*this != rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return *this;
}

Fixed & Point::getX( void ):
{
	return this->_x;
}

Fixed & Point::getY( void ):
{
	return this->_y;
}
