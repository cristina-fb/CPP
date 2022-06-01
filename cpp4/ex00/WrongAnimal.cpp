#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type("Default") { std::cout << "Default WrongAnimal Constructor Called" << std::endl; }

WrongAnimal::WrongAnimal( std::string type ): type(type) { std::cout << "WrongAnimal " << type << " Constructor Called" << std::endl; }

WrongAnimal::WrongAnimal( WrongAnimal & src )
{ 
	std::cout << "Copy WrongAnimal Constructor Called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal( void ) { std::cout << "WrongAnimal Destructor Called" << std::endl; }

WrongAnimal & WrongAnimal::operator=( WrongAnimal & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void WrongAnimal::makeSound( void ) const { std::cout << "* making Wronganimal sounds *" << std::endl; }

std::string WrongAnimal::getType( void ) const { return this->type; }
