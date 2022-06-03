#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	this->_name = "Default";
	this->ClapTrap::_name = "Default_clap_name";
	this->_hitpoints = this->FragTrap::_hitpoints;
    this->_energypoints = this->ScavTrap::_energypoints;
    this->_damage = this->FragTrap::_damage;
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}
DiamondTrap::DiamondTrap( std::string name): _name(name)
{
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitpoints = this->FragTrap::_hitpoints;
    this->_energypoints = this->ScavTrap::_energypoints;
    this->_damage = this->FragTrap::_damage;
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}
DiamondTrap::DiamondTrap( DiamondTrap & src )
{
	*this = src;
	std::cout << "Copy DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) { std::cout << "DiamondTrap " << this->_name << " has been destroyed" << std::endl; }

DiamondTrap & DiamondTrap::operator=(DiamondTrap & rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getDiamondName();
		this->ClapTrap::_name = rhs.getName();
	}
	return *this;
}

void DiamondTrap::whoAmI( void ) { std::cout << "I am " << this->_name << "! (" << this->ClapTrap::_name << ")" << std::endl; }

std::string DiamondTrap::getDiamondName( void ) { return this->_name; }
