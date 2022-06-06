#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	this->_dname = "Default";
	this->name = "Default_clap_name";
	this->hitpoints = this->FragTrap::hitpoints;
    this->energypoints = this->ScavTrap::energypoints;
    this->damage = this->FragTrap::damage;
	std::cout << "DiamondTrap " << this->_dname << " has been created" << std::endl;
}
DiamondTrap::DiamondTrap( std::string name)
{
	this->_dname = name;
	this->name = name + "_clap_name";
	this->hitpoints = this->FragTrap::hitpoints;
    this->energypoints = this->ScavTrap::energypoints;
    this->damage = this->FragTrap::damage;
	std::cout << "DiamondTrap " << this->_dname << " has been created" << std::endl;
}
DiamondTrap::DiamondTrap( DiamondTrap & src )
{
	*this = src;
	std::cout << "Copy DiamondTrap " << this->_dname << " has been created" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) { std::cout << "DiamondTrap " << this->_dname << " has been destroyed" << std::endl; }

DiamondTrap & DiamondTrap::operator=(DiamondTrap & rhs)
{
	if(this != &rhs)
	{
		this->_dname = rhs.getDiamondName();
		this->name = rhs.name;
		this->hitpoints = rhs.hitpoints;
		this->energypoints = rhs.energypoints;
		this->damage = rhs.damage;
	}
	return *this;
}

void DiamondTrap::whoAmI( void ) { std::cout << "I am " << this->getDiamondName() << "! (" << this->name << ")" << std::endl; }

std::string DiamondTrap::getDiamondName( void ) { return this->_dname; }
