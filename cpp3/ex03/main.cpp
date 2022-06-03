#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( int argc, char** argv)
{
    if (argc == 1)
    {
        DiamondTrap A;
        DiamondTrap B("Paco");
        DiamondTrap C = B;

        B.attack( "Mariano" );
        B.takeDamage( 7 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        B.beRepaired( 8 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        B.guardGate();
        B.highFivesGuys();
        B.whoAmI();
    }
    else
        std::cout << argv[0] << "doesn't accept parameters" << std::endl;
    return 0;
}
