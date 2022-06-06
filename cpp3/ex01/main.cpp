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
        ClapTrap D("Antonio");

        std::cout << std::endl;
        B.attack( "Mariano" );
        D.attack( "Mariano" );
        B.takeDamage( 7 );
        D.takeDamage( 7 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        std::cout << "Hitpoints of " << D.getName() << " are " << D.getHitpoints() << " points!" << std::endl;
        B.beRepaired( 8 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        B.guardGate();
        std::cout << std::endl;
    }
    else
        std::cout << argv[0] << "doesn't accept parameters" << std::endl;
    return 0;
}
