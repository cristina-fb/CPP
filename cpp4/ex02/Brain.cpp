/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:40:30 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:40:31 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain( void ): _n_ideas(0)
{
	std::cout << "Brain Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "";
	}
}

Brain::Brain( Brain & src )
{
	std::cout << "Copy Brain Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "";
	}
	*this = src;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain & Brain::operator=( Brain & rhs )
{
	int n;
	std::cout << "Copying Brains..." << std::endl;
	if (this != &rhs)
	{
		n = rhs.get_n_ideas();
		for (int i = 0; i < n; i++)
			this->set_ideas(rhs.get_ideas()[i]);
	}
	return *this;
}

int Brain::get_n_ideas( void )
{
	return this->_n_ideas;
}

std::string* Brain::get_ideas( void )
{
	return this->_ideas;
}

void Brain::set_ideas( std::string myidea )
{
	if ((this->_n_ideas < 100) && (this->_n_ideas >= 0))
	{
		this->_ideas[this->_n_ideas] = myidea;
		this->_n_ideas++;
	}
	else
		std::cout << "No more space on the brain T.T" << std::endl;
}
