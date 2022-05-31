#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cout << argv[0] << " doesn't accept parameters" << std::endl;
		return 0;
	}
	Point a(Fixed(2.5f), Fixed(4.5f)), b(Fixed(2.5f), Fixed(2)), c(Fixed(6), Fixed(2)), p(Fixed(3), Fixed(3));
	if (bsp(a, b, c, p))
		std::cout << "Point 1 is inside triangle" << std::endl;
	else
		std::cout << "Point 1 is not part of the triangle" << std::endl;
	Point q(Fixed(-8), Fixed(-3.3f));
	if (bsp(a, b, c, q))
		std::cout << "Point 2 is inside triangle" << std::endl;
	else
		std::cout << "Point 2 is not part of the triangle" << std::endl;
	Point r(Fixed(2.5f), Fixed(4.5f));
	if (bsp(a, b, c, r))
		std::cout << "Point 3 is inside triangle" << std::endl;
	else
		std::cout << "Point 3 is not part of the triangle" << std::endl;
	return 0;
}
