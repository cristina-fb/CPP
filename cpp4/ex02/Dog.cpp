/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:13:26 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:49:38 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << "Dog constructor called!" << std::endl;
	this->type = "Dog";
	this->_dogBrain = new Brain();
}

Dog::Dog( Dog & src )
{ 
	std::cout << "Copy dog constructor called!" << std::endl;
	this->_dogBrain = new Brain();
	*this = src;
}

Dog::~Dog( void )
{
	delete this->_dogBrain;
	std::cout << "Dog destructor called!" << std::endl;
}

Dog & Dog::operator=( Dog & rhs )
{
	std::cout << "Copying puppies n.n " << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->_dogBrain) = *(rhs.getDogBrain());
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "* woof woof *" << std::endl;
}

Brain* Dog::getDogBrain( void ) const
{
	return this->_dogBrain;
}
