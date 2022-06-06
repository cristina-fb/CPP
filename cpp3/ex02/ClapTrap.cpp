#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): name("Default"), hitpoints(10), energypoints(10), damage(0)
{
    std::cout << "ClapTrap " << this->name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string name): name(name), hitpoints(10), energypoints(10), damage(0)
{
    std::cout << "ClapTrap " << this->name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap & src )
{
    *this = src;
    std::cout << "Copy ClapTrap " << this->name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap " << this->name << " has been destroyed" << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap & src )
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

void ClapTrap::attack(std::string const & target)
{
    std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitpoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is death" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has been attacked, losing ";
        if (this->hitpoints < (int)amount)
        {
            std::cout << this->hitpoints;
            this->hitpoints = 0;
        }
        else
        {
            std::cout << amount;
            this->hitpoints -= amount;
        }
        std::cout << " hitpoints!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " has been healed, recovering " << amount << " hitpoints!" << std::endl;
    this->hitpoints += amount;
}

int ClapTrap::getHitpoints( void ){ return this->hitpoints; }

int ClapTrap::getEnergypoints( void ){ return this->energypoints; }

int ClapTrap::getDamage( void ){ return this->damage; }

std::string ClapTrap::getName( void ){ return this->name; }
