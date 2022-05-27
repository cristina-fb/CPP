#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool isTriangle(Point const & a, Point const & b, Point const & c)
{
	if (((a.getX()).getRawBits() == (b.getX()).getRawBits()) && ((c.getX()).getRawBits() == (b.getX()).getRawBits()))
	{
		return false;
	}
	else if (((a.getY()).getRawBits() == (b.getY()).getRawBits()) && ((c.getY()).getRawBits() == (b.getY()).getRawBits()))
		return false;
	else if (((a.getY()).getRawBits() == (b.getY()).getRawBits()) && ((a.getX()).getRawBits() == (b.getX()).getRawBits())) //Más casos bc y ca
		return false;
	return true;
}

/*bool isInPlane(Point const a, Point const b)
{
	Fixed slope = 
}*/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (!isTriangle(a, b, c))
	{
		//std::cout << "The points doesn't form a triangle!" << std::endl;
		return false;
	}
	std::cout << "HOLA";
	//return (isInPlane(a, b) && isInPlane(b, c) && isInPlane(c, a));
	return true;
}
