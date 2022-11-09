/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:40:52 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:40:54 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	this->_dogBrain = new Brain();
	std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog( Dog & src )
{ 
	std::cout << "Copy Dog Constructor Called" << std::endl;
	this->_dogBrain = new Brain();
	*this = src;
}

Dog::~Dog( void )
{
	delete this->_dogBrain;
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog & Dog::operator=( Dog & rhs )
{
	std::cout << "Copying puppies n.n " << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->_dogBrain) = *(rhs.get_DogBrain());
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "* woof woof *" << std::endl;
}

Brain* Dog::get_DogBrain( void ) const
{
	return this->_dogBrain;
}
