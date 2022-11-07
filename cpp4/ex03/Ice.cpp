#include "Ice.hpp"

Ice::Ice( void ): type("ice")
{
	std::cout << "Ice Constructor" << std::endl;
}

Ice::Ice( Ice & cpy ): type("ice")
{
    std::cout << "Ice Copy Constructor" << std::endl;
}

Ice::~Ice( void )
{
    std::cout << "Ice Destructor" << std::endl;
}

Ice & Ice::operator=( Ice & asg )
{
    //Nada?
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}