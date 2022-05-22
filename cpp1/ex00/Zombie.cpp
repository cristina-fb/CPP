#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name) : _name(name)
{
    std::cout << this->_name << " zombie is alive." << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << this->_name << " zombie is death." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}