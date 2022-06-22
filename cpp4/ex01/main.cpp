#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void leaks(void)
{
	system("leaks Brain");
}

int main()
{
	atexit(leaks);
	std::cout << "------------------ PRUEBA 1 ------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	j->makeSound();
	delete j; //should not create a leak
	delete i;
	std::cout << std::endl << "------------------ PRUEBA 2 ------------------" << std::endl;
	Animal* list[4];
	list[0] = new Cat();
	list[1] = new Cat();
	list[2] = new Dog();
	list[3] = new Dog();
	for (int i = 0; i < 4; i++)
	{
		delete list[i];
	}
	std::cout << std::endl << "------------------ PRUEBA 3 ------------------" << std::endl;
	Cat * catA = new Cat();
	Cat * catB = new Cat();;
	Dog dogA;
	Dog dogB;
	(catA->getCatBrain())->ideas[0] = "hello kitty! <3";
	catB = catA;
	std::cout << (catB->getCatBrain())->ideas[0] << std::endl;
	(dogA.getDogBrain())->ideas[59] = "hello puppy! <3";
	dogB = dogA;
	std::cout << (dogB.getDogBrain())->ideas[59] << std::endl;
	delete catA;
	delete catB;
	return 0;
}
