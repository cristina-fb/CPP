/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:30 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:04:37 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << "Cat constructor called!" << std::endl;
	this->type = "Cat";
}

Cat::Cat( Cat & src )
{ 
	std::cout << "Copy cat constructor called!" << std::endl;
	*this = src;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called!" << std::endl;
}

Cat & Cat::operator=( Cat & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "* meow meow *" << std::endl;
}
