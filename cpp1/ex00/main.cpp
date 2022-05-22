#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie zombie1("Paco");
	Zombie *zombie2 = newZombie("Antonio");

	randomChump("Mariano");
	zombie2->announce();
	zombie1.announce();
	delete zombie2;
}