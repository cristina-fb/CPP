/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:47 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/27 17:13:55 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

span::span( void ): _N(0)
{

}

span::span( unsigned int N ): _N(N)
{

}

span::span( span & cpy )
{

}

span::~span( void )
{

}

span & span::operator=( span & asg )
{

}

void span::addNumber( int number )
{

}

int span::shortestSpan( void ) const
{

}

int span::longestSpan( void ) const
{

}

unsigned int span::getN( void ) const
{
	return this->_N;
}