#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog( Dog & src )
{ 
	*this = src;
	std::cout << "Copy Dog Constructor Called" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog & Dog::operator=( Dog & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "* woof woof *" << std::endl;
}
