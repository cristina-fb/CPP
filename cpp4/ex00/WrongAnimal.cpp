/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:01:12 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:01:13 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type("Default")
{
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ): type(type)
{
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal & src )
{ 
	std::cout << "Copy WrongAnimal Constructor Called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
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
	std::cout << "* making Wronganimal sounds *" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return this->type;
}
