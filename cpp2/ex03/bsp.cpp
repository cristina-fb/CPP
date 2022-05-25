#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool isTriangle(Point a, Point b, Point c)
{
	if (((a.getX()).getRawBits() == (b.getX()).getRawBits()) && ((c.getX()).getRawBits() == (b.getX()).getRawBits()))
	{
		std::cout << a.getX() << "---" << b.getX();
		return false;
	}
	else if (((a.getY()).getRawBits() == (b.getY()).getRawBits()) && ((c.getY()).getRawBits() == (b.getY()).getRawBits()))
		return false;
	return true;
}

bool isInPlane(Point const a, Point const b)
{
	Fixed slope = 
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << a.getX();
	if (!isTriangle(a, b, c))
	{
		std::cout << "The points doesn't form a triangle!" << std::endl;
		return false;
	}
	//return (isInPlane(a, b) && isInPlane(b, c) && isInPlane(c, a));
	return true;
}
