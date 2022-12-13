/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:00:50 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/13 19:23:47 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): _target("Default")
{
	std::cout << "RobotomyRequest Form Default Constructor!" << std::endl;
}
	
RobotomyRequestForm::RobotomyRequestForm( std::string target ): _target(target)
{
	std::cout << "RobotomyRequest Form Constructor!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm & cpy ): _target(cpy.getTarget())
{
	std::cout << "RobotomyRequest Form Copy Constructor!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequest Form Destructor!" << std::endl;
}
		
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm & asg)
{
	if (this != &asg)
	{
		this->_target = asg.getTarget();
	}
	return *this;
}
		
std::string RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const //CAMBIAR
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
