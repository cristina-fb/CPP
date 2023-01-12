/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:47 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/12 17:42:12 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

span::span( void ): _n(0)
{}

span::span( unsigned int N ): _n(N)
{}

span::span( span & cpy )
{
	*this = cpy;
}

span::~span( void )
{}

span & span::operator=( span & asg )
{
	if (this != &asg)
	{
		this->_tab.clear();
		this->_n = asg.getN();
		this->_tab = asg.getTab();
	}
}

void span::addNumber( int number )
{
	if (this->_tab.size() >= this->_n)
	{
		throw("List is aready full! :(");
	}
	else
	{
		this->_tab.push_back(number);
	}
}

int span::shortestSpan( void ) const
{
	if (this->_tab.size() < 2)
		throw("Can't calculate span! :(");
	return();
}

int span::longestSpan( void ) const
{
	if (this->_tab.size() < 2)
		throw("Can't calculate span! :(");
	return (*(std::max_element(this->_tab.begin(), this->_tab.end())) - *(std::min_element(this->_tab.begin(), this->_tab.end())));
}

std::list<int> span::getTab( void ) const
{
	return this->_tab;
}

unsigned int span::getN( void ) const
{
	return this->_n;
}
