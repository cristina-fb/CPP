#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
    this->_name = "Default";
    this->_hitpoints = 100;
    this->_energypoints = 50;
    this->_damage = 20;
    std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string name)
{
    this->_name = name;
    this->_hitpoints = 100;
    this->_energypoints = 50;
    this->_damage = 20;
    std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap & src )
{
    *this = src;
    std::cout << "Copy ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap " << this->_name << " has been destroyed"<< std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap & src )
{
    if (this != & src)
    {
        this->_name = src.getName();
        this->_hitpoints = src.getHitpoints();
        this->_energypoints = src.getHitpoints();
        this->_damage = src.getDamage();
        return *this;
    }
    return *this;
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "Scavtrap " << this->_name << " have entered in gate keeper mode!" << std::endl;
}
