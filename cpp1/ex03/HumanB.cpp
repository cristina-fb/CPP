#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_my_weapon = NULL;
};

HumanB::~HumanB( void )
{
};

void HumanB::attack( void )
{
	std::cout << this->_name << " attacks with his ";
	if (this->_my_weapon == NULL)
	{
		std::cout << "hands" << std::endl;
	}
	else
	{
		std::cout << this->_my_weapon->getType() << std::endl;
	}
};

void HumanB::setWeapon( Weapon& my_weapon)
{
	this->_my_weapon = &my_weapon;
}