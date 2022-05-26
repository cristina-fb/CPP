#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	this->_name = "Default";
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}
DiamondTrap::DiamondTrap( std::string name): _name(name)
{
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}
DiamondTrap::DiamondTrap( DiamondTrap & src )
{
	*this = src;
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap & rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return *this;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << this->_name << "!" << std::endl;
}

std::string DiamondTrap::getName( void ) { return this->_name; }
