#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon& my_weapon );
		~HumanA( void );
		void attack ( void );

	private:
		Weapon& _my_weapon;
		std::string _name;
};
#endif