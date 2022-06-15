#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
	system("leaks Animal");
}

int main()
{
	atexit(leaks);
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();
	std::cout << meta->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << k->getType() << std::endl;
	std::cout << l->getType() << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();
	l->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
}
