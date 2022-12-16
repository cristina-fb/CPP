/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:01:00 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/16 15:30:48 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("ShrubberyCreation", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreation Form Default Constructor!" << std::endl;
}
	
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): Form("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreation Form Constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm & cpy ): Form("ShrubberyCreation", 145, 137), _target(cpy.getTarget())
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

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() > this->getGradeExec())
		{
			throw(GradeTooLowException());
		}
		else
		{
			std::string filename = this->_target + "_shrubbery";
			std::ofstream outfile (filename);
			outfile << "		               ,@@@@@@@," << std::endl;
			outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			outfile << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
			outfile << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			outfile << "       |o|        | |         | |" << std::endl;
			outfile << "       |.|        | |         | |" << std::endl;
			outfile << "_\\__\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
			outfile.close();
		}
	}
	else
	{
		throw(FormNotSigned());
	}
}
