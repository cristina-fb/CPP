#include <iostream>
#include "ClapTrap.hpp"

int main( int argc, char** argv)
{
    if (argc == 1)
    {
        ClapTrap A;
        ClapTrap B("Paco");
        ClapTrap C = B;

        B.attack( "Mariano" );
        B.attack( "Mariano" );
        std::cout << "Total damage made is " << B.getDamage() << " points!" << std::endl;
        B.takeDamage( 7 );
        std::cout << "Energy points of " << B.getName() << " are " << B.getEnergypoints() << " points!" << std::endl;
        B.takeDamage( 5 );
        std::cout << "Energy points of " << B.getName() << " are " << B.getEnergypoints() << " points!" << std::endl;
        B.takeDamage( 5 );
        std::cout << "Energy points of " << B.getName() << " are " << B.getEnergypoints() << " points!" << std::endl;
        B.beRepaired( 8 );
        std::cout << "Energy points of " << B.getName() << " are " << B.getEnergypoints() << " points!" << std::endl;
    }
    else
        std::cout << argv[0] << "doesn't accept parameters" << std::endl;
    return 0;
}
