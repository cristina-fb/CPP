#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(int argc, char **argv)
{
	Point a(Fixed(2.1f), Fixed(3.1f));
	Point b(Fixed(2.1f), Fixed(3.1f));
	Point c(Fixed(7.8f), Fixed(6.2f));
	Point point(Fixed(4.2f), Fixed(4.2f));

	if (argc != 1)
	{
		std::cout << argv[0] << "doesn't accept parameters" << std::endl;
	}
	if (bsp(a, b, c, point))
	{
		std::cout << "Point is inside triangle" << std::endl;
		return 0;
	}
	std::cout << "Point is not part of the triangle" << std::endl;
	return 0;
}
