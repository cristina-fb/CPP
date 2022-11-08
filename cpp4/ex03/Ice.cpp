#include "Ice.hpp"

Ice::Ice( void )
{
    this->type = "ice";
	std::cout << "Ice Constructor" << std::endl;
}

Ice::Ice( Ice & cpy )
{
    this->type = "ice";
    std::cout << "Ice Copy Constructor" << std::endl;
    *this = cpy;
}

Ice::~Ice( void )
{
    std::cout << "Ice Destructor" << std::endl;
}

Ice & Ice::operator=( Ice & asg )
{
    //Nada?
    std::cout << asg.getType() << std::endl;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
