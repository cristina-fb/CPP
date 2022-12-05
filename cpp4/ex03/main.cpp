/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:33:12 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/05 18:18:09 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

/*void leaks( void )
{
	system("leaks Materia");
}*/

int main( void )
{
	//atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Cure *my_cure = new Cure();
	src->learnMateria(my_cure);
	delete my_cure;
	std::cout << "-----------------------------------------" << std::endl;

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(13);
	me->unequip(-42);
	//me->unequip(3);
	//me->use(3, *bob);
	std::cout << "-----------------------------------------" << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}
