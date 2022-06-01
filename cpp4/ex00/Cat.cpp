#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat( Cat & src )
{ 
	std::cout << "Copy Cat Constructor Called" << std::endl;
	*this = src;
}

Cat::~Cat( void ) { std::cout << "Cat Destructor Called" << std::endl; }

Cat & Cat::operator=( Cat & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void Cat::makeSound( void ) const { std::cout << "* meow meow *" << std::endl; }
