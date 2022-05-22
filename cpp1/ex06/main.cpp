#include <iostream>
#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen my_karen;

	if (argc == 2)
	{
		my_karen.complain(argv[1]);
	}
	else if (argc == 1)
	{
		my_karen.complain("");
	}
	return(0);
}