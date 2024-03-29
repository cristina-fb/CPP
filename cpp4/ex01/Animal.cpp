/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:12:17 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:32:56 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ): type("Default")
{
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal( std::string type ): type(type)
{
	std::cout << "Animal " << type << " constructor called!" << std::endl;
}

Animal::Animal( Animal & src )
{ 
	std::cout << "Copy animal constructor called!" << std::endl;
	*this = src;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called!" << std::endl;
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

void Animal::setType( std::string myType )
{
	this->type = myType;
}
