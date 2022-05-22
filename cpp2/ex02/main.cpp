#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed w(42.42f);
	Fixed x(21.21f);
	Fixed y(84.84f);
	Fixed z(84.84f);

	std::cout << "w < x " << (w < x) << std::endl;
	std::cout << "w > x " << (w > x) << std::endl;
	std::cout << "w <= x " << (w <= x) << std::endl;
	std::cout << "w >= x " << (w >= x) << std::endl;
	std::cout << "y == z " << (y == z) << std::endl;
	std::cout << "y != z " << (y != z) << std::endl;
	std::cout << "w + x " << (w + x) << std::endl;
	std::cout << "w - x " << (w - x) << std::endl;
	std::cout << "y * z " << (y * z) << std::endl;
	std::cout << "y / z " << (y / z) << std::endl;

	Fixed a;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
