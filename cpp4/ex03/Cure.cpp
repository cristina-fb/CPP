#include "Cure.hpp"

Cure::Cure( void ): type("cure")
{
	std::cout << "Cure Constructor" << std::endl;
}

Cure::Cure(Cure & cpy ): type("cure")
{
    std::cout << "Cure Copy Constructor" << std::endl;
}

Cure::Cure( void )
{
    std::cout << "Cure Destructor" << std::endl;
}

Cure &Cure::operator=(Cure & asg )
{
    //Nada?
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds*" << std::endl;
}