#include <iostream>
#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
}

Brain::Brain( Brain & src )
{
	*this = src;
	std::cout << "Copy Brain Constructor Called" << std::endl;
}
Brain::~Brain( void ) { std::cout << "Brain Destructor Called" << std::endl; }

Brain & Brain::operator=( Brain & rhs )
{
	std::cout << "Copying Brains..." << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}
