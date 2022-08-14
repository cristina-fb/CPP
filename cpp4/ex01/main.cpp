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
	Cat * a = new Cat();
	Cat * b = new Cat();
	*b = *a;
	std::cout << a->getCatBrain() << std::endl;
	std::cout << b->getCatBrain() << std::endl;
	delete a;
	delete b;
	/*std::cout << "------------------ PRUEBA 1 ------------------" << std::endl;
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
	std::cout << catA->getCatBrain() << std::endl;
	std::cout << catB->getCatBrain() << std::endl;
	delete catA;
	delete catB
	Brain * a = new Brain();
	Brain * b = new Brain();
	std::cout << "puntero a" << &a << std::endl;
	std::cout << "puntero b" << &b << std::endl;
	a = b;
	std::cout << "puntero a" << &a << std::endl;
	std::cout << "puntero b" << &b << std::endl;
	std::cout << a->ideas << std::endl;
	std::cout << b->ideas << std::endl;*/
	return 0;
}
