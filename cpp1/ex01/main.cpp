#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int N = 5;
	Zombie *list = zombieHorde(N, "Paco");

	for(int i = 0; i < N; i++)
	{
		list[i].announce();
	}
	delete [] list;
}