#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(int argc, char **argv)
{
	Point a(Fixed(2), Fixed(4));
	Point b(Fixed(2), Fixed(4));
	Point c(Fixed(2), Fixed(4));
	Point point(Fixed(2), Fixed(3));

	if (argc != 1)
	{
		std::cout << argv[0] << " doesn't accept parameters" << std::endl;
		return 0;
	}
	if (bsp(a, b, c, point))
	{
		std::cout << "Point is inside triangle" << std::endl;
		return 0;
	}
	std::cout << "Point is not part of the triangle" << std::endl;
	return 0;
}
