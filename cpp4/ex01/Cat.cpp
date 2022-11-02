#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	this->_catBrain = new Brain();
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat( Cat & src )
{ 
	std::cout << "Copy Cat Constructor Called" << std::endl;
	this->_catBrain = new Brain();
	*this = src;
}

Cat::~Cat( void )
{
	delete this->_catBrain;
	std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "* meow meow *" << std::endl;
}

Cat & Cat::operator=( Cat & rhs )
{
	std::cout << "Copying kitties ^.^ " << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->_catBrain) = *(rhs.get_CatBrain());
	}
	return *this;
}

Brain* Cat::get_CatBrain( void ) const
{
	return this->_catBrain;
}
