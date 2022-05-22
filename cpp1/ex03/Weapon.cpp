#include "Weapon.hpp"

Weapon::Weapon( std::string name ): _type(name)
{
};

Weapon::~Weapon( void )
{
};

void Weapon::setType( std::string type )
{
	this->_type = type;
};

const std::string& Weapon::getType( void )
{
	return (this->_type);
};