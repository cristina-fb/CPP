#include "Materia.hpp"

AMateria::AMateria( void ): type("Default")
{
	std::cout << "Materia Default Constructor" << std::endl;
}

AMateria::AMateria( std::string const & type ): type(type)
{
	std::cout << "Materia " << type << " Constructor" << std::endl;
}

Amateria::AMateria( AMateria & cpy )
{
	std::cout << "Materia Copy Constructor" << std::endl;
	*this = cpy;
}

AMateria::~AMateria( void )
{
	std::cout << "Materia " << type << " Destructor" << std::endl;
}

AMateria & AMateria::operator=( AMateria & asg )
{
	if (*this != asg)
	{
		this->type = asg.getType();
	}
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void use(ICharacter& target)
{
	std::cout << "Using " << this->type << " against " << target.getName() << std::endl;
}
