/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:00:50 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/16 15:30:00 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): Form("RobotomyRequest", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequest Form Default Constructor!" << std::endl;
}
	
RobotomyRequestForm::RobotomyRequestForm( std::string target ): Form("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "RobotomyRequest Form Constructor!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm & cpy ): Form("RobotomyRequest", 72, 45), _target(cpy.getTarget())
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

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() > this->getGradeExec())
		{
			throw(GradeTooLowException());
		}
		else
		{
			std::cout << "SDFJNDFOIVFKLLKSLKSSALLAKLVLK DKAKLDKLSDKSDVVLKSDVVKSD LSWWWWDWDWWCWXXXXWWWXWQW" << std::endl;
			std::cout << "BKKDFLJ DFGJÑDFK GDFÑJGLÑDFKGJÑDLFKÑGJ DFÑÑGJD FDÑF GÑFDIGJDLFK DLFKLGJÑDLFKÑ D" << std::endl;
			std::cout << "OIFDUGOIDF UDFOIOG UDFOG SÑDKFWEPORIEPOW 90WR SFKJSDLFK SKFJSDLKFJLSDKFJILSFJLS" << std::endl;
			srand(time(NULL));
			int i = rand() % 2;
			if (i == 0)
			{
				std::cout << this->_target << " has been robotomized successfully!" << std::endl;
			}
			else
			{
				std::cout << "ERROR! " << this->_target << " hasn't been robotomized :(" << std::endl;
			}
		}
	}
	else
	{
		throw(FormNotSigned());
	}
}
