#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
    this->_name = "Default";
    this->_hitpoints = 100;
    this->_energypoints = 100;
    this->_damage = 30;
    std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::FragTrap( std::string name)
{
    this->_name = name;
    this->_hitpoints = 100;
    this->_energypoints = 100;
    this->_damage = 30;
    std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::FragTrap( FragTrap & src )
{
    *this = src;
    std::cout << "Copy FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap " << this->_name << " has been destroyed"<< std::endl;
}

FragTrap & FragTrap::operator=( FragTrap & src )
{
    if (this != & src)
    {
        this->_name = src.getName();
        this->_hitpoints = src.getHitpoints();
        this->_energypoints = src.getEnergypoints();
        this->_damage = src.getDamage();
        return *this;
    }
    return *this;
}

void FragTrap::attack(std::string const & target)
{
    std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "Fragtrap " << this->_name << " wants to hi five!" << std::endl;
}
