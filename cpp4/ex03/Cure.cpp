/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:32:30 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 16:32:31 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void )
{
    this->type = "cure";
	std::cout << "Cure Constructor" << std::endl;
}

Cure::Cure(Cure & cpy )
{
    this->type = cpy.getType();
    std::cout << "Cure Copy Constructor" << std::endl;
}

Cure::~Cure( void )
{
    std::cout << "Cure Destructor" << std::endl;
}

Cure &Cure::operator=(Cure & asg )
{
    std::cout << "Both materias are " << asg.getType() << " materias!" << std::endl;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds*" << std::endl;
}
