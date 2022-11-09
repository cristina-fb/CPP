/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:59:59 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:00:02 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ): type("Default")
{
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal( std::string type ): type(type)
{
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal( Animal & src )
{ 
	std::cout << "Copy Animal Constructor Called" << std::endl;
	*this = src;
}

Animal::~Animal( void )
{
	std::cout << "Animal Destructor Called" << std::endl;
}

Animal & Animal::operator=( Animal & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

void Animal::makeSound( void ) const
{
	std::cout << "* making animal sounds *" << std::endl;
}

std::string Animal::getType( void ) const
{
	return this->type;
}
