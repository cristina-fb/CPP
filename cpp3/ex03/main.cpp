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
        ClapTrap D("Antonio");
        ScavTrap E("Manuel");
        FragTrap F("Juancho");

        std::cout << std::endl;
        B.attack( "Mariano" );
        D.attack( "Mariano" );
        E.attack( "Mariano" );
        F.attack( "Mariano" );
        B.takeDamage( 7 );
        D.takeDamage( 7 );
        E.takeDamage( 7 );
        F.takeDamage( 7 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        std::cout << "Hitpoints of " << D.getName() << " are " << D.getHitpoints() << " points!" << std::endl;
        std::cout << "Hitpoints of " << E.getName() << " are " << E.getHitpoints() << " points!" << std::endl;
        std::cout << "Hitpoints of " << F.getName() << " are " << F.getHitpoints() << " points!" << std::endl;
        B.beRepaired( 8 );
        std::cout << "Hitpoints of " << B.getName() << " are " << B.getHitpoints() << " points!" << std::endl;
        B.guardGate();
        B.highFivesGuys();
        B.whoAmI();
        std::cout << std::endl;
    }
    else
        std::cout << argv[0] << "doesn't accept parameters" << std::endl;
    return 0;
}
