#include <iostream>
#include "Karen.hpp"

int main(void)
{
	Karen my_karen;

	std::cout << "------- DEBUG -------" << std::endl;
	my_karen.complain("debug");
	std::cout << "------- INFO -------" << std::endl;
	my_karen.complain("info");
	std::cout << "------- WARNING -------" << std::endl;
	my_karen.complain("warning");
	std::cout << "------- ERROR -------" << std::endl;
	my_karen.complain("error");
	std::cout << "------- OTHER -------" << std::endl;
	my_karen.complain("sdfksdñlfsñfkds");
	return(0);
}