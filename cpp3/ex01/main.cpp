#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( int argc, char** argv)
{
    if (argc == 1)
    {
        ScavTrap A;
        ScavTrap B("Paco");
        ScavTrap C = B;

        B.attack( "Mariano" );
        B.takeDamage( 7 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        B.beRepaired( 8 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        B.guardGate();
    }
    else
        std::cout << argv[0] << "doesn't accept parameters" << std::endl;
    return 0;
}
