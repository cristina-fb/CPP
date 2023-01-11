/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:04:30 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 12:16:32 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

Awesome::Awesome( void ): _n( 42 ) { return; }
Awesome::Awesome( Awesome & cpy )
{
    *this = cpy;
}
Awesome::~Awesome( void ) {}
Awesome & Awesome::operator=( Awesome & asg )
{
    if (this != &asg)
    {
        this->_n = asg.get();
    }
    return *this;
}
int Awesome::get( void ) const { return this->_n; }
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o;}
