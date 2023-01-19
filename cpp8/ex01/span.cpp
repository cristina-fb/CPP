/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:47 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/19 15:38:49 by crisfern         ###   ########.fr       */
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
	return *this;
}

void span::addNumber( int number )
{
	if (this->_tab.size() >= this->_n)
		throw("List is already full! :(");
	else
		this->_tab.push_back(number);
}

void span::addNumber( std::list<int>::iterator begin, std::list<int>::iterator end )
{
	std::list<int>::iterator aux = this->_tab.end();
	int size_span = this->_tab.size();
	int size_it = std::distance(begin, end);
	if ((size_it + size_span) <= this->_n)
	{
		this->_tab.insert(this->_tab.end(), begin, end);
		return;
	}
	else if (size_span < this->_n)
	{
		int a = -(size_it - (this->_n - size_span));
		std::advance(end, a);
		this->_tab.insert(this->_tab.end(), begin, end);
	}
	throw("List is already full! :(");
}

int span::shortestSpan( void ) const
{
	std::list<int> aux;
	if (this->_tab.size() < 2)
		throw("Can't calculate span! :(");
	aux = this->_tab;
	aux.sort();
	std::adjacent_difference(aux.begin(), aux.end(), aux.begin());
	return(*(std::min_element(++(aux.begin()), aux.end())));
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
