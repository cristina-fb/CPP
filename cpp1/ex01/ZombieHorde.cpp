#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie_list = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		zombie_list[i].set_name(name);
	}
	return(zombie_list);
}