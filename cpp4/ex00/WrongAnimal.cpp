/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:01:12 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:09:37 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type("Default")
{
	std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ): type(type)
{
	std::cout << "WrongAnimal " << type << " constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal & src )
{ 
	std::cout << "Copy wrongAnimal constructor called!" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "* making wronganimal sounds *" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return this->type;
}

void WrongAnimal::setType( std::string myType )
{
	this->type = myType;
}
