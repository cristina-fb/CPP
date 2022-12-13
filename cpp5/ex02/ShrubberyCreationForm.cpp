/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:01:00 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/13 19:31:21 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): _target("Default")
{
	std::cout << "ShrubberyCreation Form Default Constructor!" << std::endl;
}
	
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): _target(target)
{
	std::cout << "ShrubberyCreation Form Constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm & cpy ): _target(cpy.getTarget())
{
	std::cout << "ShrubberyCreation Form Copy Constructor!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreation Form Destructor!" << std::endl;
}
		
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm & asg)
{
	if (this != &asg)
	{
		this->_target = asg.getTarget();
	}
	return *this;
}
		
std::string ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const //CAMBIAR
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
