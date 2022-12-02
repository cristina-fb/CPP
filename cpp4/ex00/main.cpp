/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:38:33 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:17:24 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "< WRONGCAT AS A WRONGANIMAL>" << std::endl;
	const WrongAnimal* l = new WrongCat();
	std::cout << l->getType() << std::endl;
	l->makeSound();
	delete l;
	
	std::cout << "----------------------------" << std::endl;
	std::cout << "< WRONGCAT AS A WRONGCAT>" << std::endl;
	const WrongCat* m = new WrongCat();
	std::cout << m->getType() << std::endl;
	m->makeSound();
	delete m;
	return 0;
}
