#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
    std::cout << "The zombie is alive." << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << this->_name << " zombie is death." << std::endl;
}

void Zombie::announce( void ) const
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name( std::string name)
{
    this->_name = name;
}