/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:00:46 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/16 15:29:10 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): Form("PresidentialPardon", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardon Form Default Constructor!" << std::endl;
}
	
PresidentialPardonForm::PresidentialPardonForm( std::string target ): Form("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardon Form Constructor!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm & cpy ): Form("PresidentialPardon", 25, 5), _target(cpy.getTarget())
{
	std::cout << "PresidentialPardon Form Copy Constructor!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardon Form Destructor!" << std::endl;
}
		
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm & asg)
{
	if (this != &asg)
	{
		this->_target = asg.getTarget();
	}
	return *this;
}
		
std::string PresidentialPardonForm::getTarget( void ) const
{
	return this->_target;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() > this->getGradeExec())
		{
			throw(GradeTooLowException());
		}
		else
		{
			std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
		}
	}
	else
	{
		throw(FormNotSigned());
	}
}
