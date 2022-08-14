#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << "Cat Constructor Called" << std::endl;
	this->type = "Cat";
	this->catBrain = new Brain();
}

Cat::Cat( Cat & src )
{ 
	std::cout << "Copy Cat Constructor Called" << std::endl;
	this->catBrain = new Brain();
	*this = src;
}

Cat::~Cat( void )
{
	delete this->catBrain;
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat & Cat::operator=( Cat & rhs )
{
	std::cout << "Copying kitties ^.^ " << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->catBrain) = *(rhs.getCatBrain());
	}
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "* meow meow *" << std::endl;
}

Brain* Cat::getCatBrain( void ) const
{
	return this->catBrain;
}
