#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->type = "WrongCat";
	std::cout << "WrongCat Constructor Called" << std::endl;
}

WrongCat::WrongCat( WrongCat & src )
{ 
	std::cout << "Copy WrongCat Constructor Called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat( void ) { std::cout << "WrongCat Destructor Called" << std::endl; }

WrongCat & WrongCat::operator=( WrongCat & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void WrongCat::makeSound( void ) const { std::cout << "* WrongCat goes meow meow *" << std::endl; }
