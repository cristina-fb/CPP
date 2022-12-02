/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:44 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:04:24 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog( Dog & src )
{ 
	*this = src;
	std::cout << "Copy dog constructor called!" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called!" << std::endl;
}

Dog & Dog::operator=( Dog & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "* woof woof *" << std::endl;
}
