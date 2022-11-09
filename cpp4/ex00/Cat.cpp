/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:30 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:00:31 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat( Cat & src )
{ 
	std::cout << "Copy Cat Constructor Called" << std::endl;
	*this = src;
}

Cat::~Cat( void )
{
	std::cout << "Cat Destructor Called" << std::endl;
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
