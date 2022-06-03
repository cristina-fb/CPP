#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap( std::string name);
		DiamondTrap( DiamondTrap & src );
		~DiamondTrap( void );

		DiamondTrap & operator=(DiamondTrap & rhs);

		void whoAmI( void );
		std::string getDiamondName( void );

	private:
        std::string _name;
};
#endif
