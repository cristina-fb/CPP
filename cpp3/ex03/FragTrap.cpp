#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
    this->name = "Default";
    this->hitpoints = 100;
    this->energypoints = 100;
    this->damage = 30;
    std::cout << "FragTrap " << this->name << " has been created" << std::endl;
}

FragTrap::FragTrap( std::string name)
{
    this->name = name;
    this->hitpoints = 100;
    this->energypoints = 100;
    this->damage = 30;
    std::cout << "FragTrap " << this->name << " has been created" << std::endl;
}

FragTrap::FragTrap( FragTrap & src )
{
    *this = src;
    std::cout << "Copy FragTrap " << this->name << " has been created" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap " << this->name << " has been destroyed"<< std::endl;
}

FragTrap & FragTrap::operator=( FragTrap & src )
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

void FragTrap::highFivesGuys( void )
{
    std::cout << "Fragtrap " << this->name << " wants to high five!" << std::endl;
}

void FragTrap::attack(std::string const & target)
{
    std::cout << "FragTrap " << this->name << " attack " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}
