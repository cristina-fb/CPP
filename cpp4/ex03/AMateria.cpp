/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:31:57 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/05 17:27:51 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ): type("Default")
{
	std::cout << "Materia Default constructor!" << std::endl;
}

AMateria::AMateria( std::string const & type ): type(type)
{
	std::cout << "Materia " << type << " constructor!" << std::endl;
}

AMateria::AMateria( AMateria & cpy )
{
	std::cout << "Materia copy constructor!" << std::endl;
	this->type = cpy.getType();
}

AMateria::~AMateria( void )
{
	std::cout << "Materia " << type << " destructor!" << std::endl;
}

AMateria & AMateria::operator=( AMateria & asg )
{
	std::cout << "Trying to asign materia " << asg.getType() << " to " << this->type << std::endl;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::setType( std::string const myType )
{
	this->type = myType;
}

void AMateria::use( ICharacter& target )
{
	std::cout << "* using " << this->type << " against " << target.getName() << " *" << std::endl;
}
