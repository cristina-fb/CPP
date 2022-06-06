#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
    this->name = "Default";
    this->hitpoints = 100;
    this->energypoints = 50;
    this->damage = 20;
    std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string name)
{
    this->name = name;
    this->hitpoints = 100;
    this->energypoints = 50;
    this->damage = 20;
    std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap & src )
{
    *this = src;
    std::cout << "Copy ScavTrap " << this->name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap " << this->name << " has been destroyed"<< std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap & src )
{
    if (this != & src)
    {
        this->name = src.name;
        this->hitpoints = src.hitpoints;
        this->energypoints = src.energypoints;
        this->damage = src.damage;
        return *this;
    }
    return *this;
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap " << this->name << " attack " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "Scavtrap " << this->name << " have entered in gate keeper mode!" << std::endl;
}
