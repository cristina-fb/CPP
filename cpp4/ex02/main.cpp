/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:41:04 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 16:15:12 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

/*void leaks(void)
{
	system("leaks Brain");
}*/

int main()
{
	//atexit(leaks);
	//Animal* myAnimal = new Animal();
	std::cout << "------------------ TEST 1 ------------------" << std::endl;
	const Animal* list[4];

	list[0] = new Cat();
	list[1] = new Cat();
	list[2] = new Dog();
	list[3] = new Dog(); 

	for (int i = 0; i < 4; i++)
		list[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete list[i];

	std::cout << "------------------ TEST 2 ------------------" << std::endl;
	Cat * a = new Cat();
	for (int i = 0; i < 50; i++)
		(a->get_CatBrain())->set_ideas("wanna eat!");
	std::cout << "Cat A has " <<(a->get_CatBrain())->get_n_ideas() << " ideas!" << std::endl << std::endl;
	Cat * b = new Cat();
	std::cout << "Cat B has " <<(b->get_CatBrain())->get_n_ideas() << " ideas!" << std::endl << std::endl;
	*b = *a;
	delete a;
	std::cout << "Cat B has " <<(b->get_CatBrain())->get_n_ideas() << " ideas!" << std::endl;
	std::cout << (b->get_CatBrain())->get_ideas()[49] << std::endl << std::endl;
	delete b;
	
	std::cout << "------------------ TEST 3 ------------------" << std::endl;
	Dog * c = new Dog();
	for (int i = 0; i < 50; i++)
		(c->get_DogBrain())->set_ideas("wanna sleep!");
	std::cout << "Dog C has " <<(c->get_DogBrain())->get_n_ideas() << " ideas!" << std::endl << std::endl;
	Dog * d = new Dog();
	std::cout << "Dog D has " <<(d->get_DogBrain())->get_n_ideas() << " ideas!" << std::endl << std::endl;
	*d = *c;
	delete c;
	std::cout << "Dog D has " <<(d->get_DogBrain())->get_n_ideas() << " ideas!" << std::endl;
	std::cout << (d->get_DogBrain())->get_ideas()[49] << std::endl << std::endl;
	delete d;
	return 0;
}
