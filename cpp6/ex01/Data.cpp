/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:41:44 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 14:53:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( void ): _str(0)
{}

Data::Data( std::string str ): _str(str)
{}

Data::Data( Data & cpy )
{
    *this = cpy;
}

Data::~Data( void )
{}

Data & Data::operator=( Data & asg )
{
    if (this != &asg)
    {
        this->_str = asg.getStr();
    }
    return *this;
}

std::string Data::getStr( void ) const
{
     return this->_str;
}
