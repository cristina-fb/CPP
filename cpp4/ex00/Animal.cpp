#include "Animal.hpp"

Animal::Animal( void ): type("Default") { std::cout << "Default Animal Constructor Called" << std::endl; }

Animal::Animal( std::string type ): type(type) { std::cout << "Animal " << type << " Constructor Called" << std::endl; }

Animal::Animal( Animal & src )
{ 
	std::cout << "Copy Animal Constructor Called" << std::endl;
	*this = src;
}

Animal::~Animal( void ) { std::cout << "Animal Destructor Called" << std::endl; }

Animal & Animal::operator=( Animal & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void Animal::makeSound( void ) const { std::cout << "* making animal sounds *" << std::endl; }

std::string Animal::getType( void ) const { return this->type; }
