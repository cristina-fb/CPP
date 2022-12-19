/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:42:52 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/19 12:30:27 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "Intern Constructor!" << std::endl;
}

Intern::Intern( Intern & cpy )
{
	(void) cpy;
	std::cout << "Intern Copy Constructor!" << std::endl;
}

Intern::~Intern( void )
{
	std::cout << "Intern Destructor!" << std::endl;
}

Intern & Intern::operator=( Intern & asg )
{
	(void) asg;
	return *this;
}

Form * Intern::makeForm( std::string formName, std::string formTarget) const
{
	int i;
	std::string str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for(i = 0; i < 3; i++)
	{
		if (str[i] == formName)
		{
			break;
		}
	}
	switch (i)
	{
		case 0:
		{
			return new ShrubberyCreationForm(formTarget);
		}
		case 1:
		{
			return new RobotomyRequestForm(formTarget);
		}
		case 2:
		{
			return new PresidentialPardonForm(formTarget);
		}
		default:
		{
			std::cout << "ERROR! Form " << formName << " doesn't exist :(" << std::endl;
		}
	}
	return 0;
}
