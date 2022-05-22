#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name );
		~HumanB( void );
		void attack ( void );
		void setWeapon( Weapon& my_weapon);

	private:
		std::string _name;
		Weapon* _my_weapon;
};
#endif