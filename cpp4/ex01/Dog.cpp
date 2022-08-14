#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << "Dog Constructor Called" << std::endl;
	this->type = "Dog";
	this->dogBrain = new Brain();
}

Dog::Dog( Dog & src )
{ 
	std::cout << "Copy Dog Constructor Called" << std::endl;
	this->dogBrain = new Brain();
	*this = src;
}

Dog::~Dog( void )
{
	delete this->dogBrain;
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog & Dog::operator=( Dog & rhs )
{
	std::cout << "Copying puppies >.<" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->dogBrain) = *(rhs.getDogBrain());
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "* woof woof *" << std::endl;
}

Brain* Dog::getDogBrain( void ) const
{
	return this->dogBrain;
}
