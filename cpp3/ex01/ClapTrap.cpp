#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): _name("Default"), _hitpoints(10), _energypoints(10), _damage(0)
{
    std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string name): _name(name), _hitpoints(10), _energypoints(10), _damage(0)
{
    std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap & src )
{
    *this = src;
    std::cout << "Copy ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap & src )
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

void ClapTrap::attack(std::string const & target)
{
    std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitpoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is death" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " has been attacked, losing ";
        if (this->_hitpoints < (int)amount)
        {
            std::cout << this->_hitpoints;
            this->_hitpoints = 0;
        }
        else
        {
            std::cout << amount;
            this->_hitpoints -= amount;
        }
        std::cout << " hitpoints!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " has been healed, recovering " << amount << " hitpoints!" << std::endl;
    this->_hitpoints += amount;
}

int ClapTrap::getHitpoints( void ){ return this->_hitpoints; }

int ClapTrap::getEnergypoints( void ){ return this->_energypoints; }

int ClapTrap::getDamage( void ){ return this->_damage; }

std::string ClapTrap::getName( void ){ return this->_name; }
