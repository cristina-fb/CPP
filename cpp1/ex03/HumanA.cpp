#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& my_weapon): _my_weapon(my_weapon), _name(name)
{
};

HumanA::~HumanA( void )
{
};

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_my_weapon.getType() << std::endl;
};