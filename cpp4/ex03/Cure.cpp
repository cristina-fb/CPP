#include "Cure.hpp"

Cure::Cure( void )
{
    this->type = "cure";
	std::cout << "Cure Constructor" << std::endl;
}

Cure::Cure(Cure & cpy )
{
    this->type = "cure";
    std::cout << "Cure Copy Constructor" << std::endl;
    *this = cpy;
}

Cure::~Cure( void )
{
    std::cout << "Cure Destructor" << std::endl;
}

Cure &Cure::operator=(Cure & asg )
{
    //Nada?
    std::cout << asg.getType() << std::endl;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds*" << std::endl;
}