/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:13:03 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:35:49 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << "Cat constructor called!" << std::endl;
	this->_catBrain = new Brain();
}

Cat::Cat( Cat & src )
{ 
	std::cout << "Copy cat constructor called!" << std::endl;
	this->_catBrain = new Brain();
	*this = src;
}

Cat::~Cat( void )
{
	delete this->_catBrain;
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "* meow meow *" << std::endl;
}

Cat & Cat::operator=( Cat & rhs )
{
	std::cout << "Copying kitties ^.^ " << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->_catBrain) = *(rhs.getCatBrain());
	}
	return *this;
}

Brain* Cat::getCatBrain( void ) const
{
	return this->_catBrain;
}
