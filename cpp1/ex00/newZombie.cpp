#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie* my_new_zombie = new Zombie(name);
    return(my_new_zombie);
}