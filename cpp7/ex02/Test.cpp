/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:30:59 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 14:49:48 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

Test::Test( void ): _n(0) {}

Test::Test( Test & cpy ) { *this = cpy; }
    
Test::Test( int n ): _n(n) {}

Test::~Test( void ) {}

Test & Test::operator=( Test & asg )
{
    if (this != &asg)
    {
        this->_n = asg.get();
    }
    return *this;
}

int Test::get( void ) const { return this->_n; }
void Test::set( int a ) { this->_n = a; }
