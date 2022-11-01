#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*void leaks(void)
{
	system("leaks Animal");
}*/

int main()
{
	//atexit(leaks);
	std::cout << "< ANIMAL >" << std::endl;
	const Animal* meta = new Animal();
	std::cout << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;
	
	std::cout << "----------------------------" << std::endl;
	std::cout << "< DOG >" << std::endl;
	const Animal* i = new Dog();
	std::cout << i->getType() << std::endl;
	i->makeSound();
	delete i;

	std::cout << "----------------------------" << std::endl;
	std::cout << "< CAT >" << std::endl;
	const Animal* j = new Cat();
	std::cout << j->getType() << std::endl;
	j->makeSound();
	delete j;

	std::cout << "----------------------------" << std::endl;
	std::cout << "< WRONGANIMAL >" << std::endl;
	const WrongAnimal* k = new WrongAnimal();
	std::cout << k->getType() << std::endl;
	k->makeSound();
	delete k;

	std::cout << "----------------------------" << std::endl;
	std::cout << "< WRONGCAT >" << std::endl;
	const WrongAnimal* l = new WrongCat();
	std::cout << l->getType() << std::endl;
	l->makeSound();
	delete l;
	
}
