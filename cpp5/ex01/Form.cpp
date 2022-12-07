/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:28:58 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/07 17:46:40 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ): _name("Default"), _gradeSign(150), _gradeExec(150), _isSigned(false)
{
	std::cout << "Form Default Constructor!" << std::endl;
}

Form::Form( std::string name, int gradeSign, int gradeExec ): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _isSigned(false)
{
	if (this->_gradeSign < 1)
	{
		throw(GradeTooHighException());
	}
	else if (this->_gradeSign > 150)
	{
		throw(GradeTooLowException());
	}
	else if (this->_gradeExec < 1)
	{
		throw(GradeTooHighException());
	}
	else if (this->_gradeExec > 150)
	{
		throw(GradeTooLowException());
	}
	std::cout << "Form " << this->_name << " Constructor!" << std::endl;
}

Form::Form( Form & cpy ): _gradeSign(150), _gradeExec(150) //ESTO NO VA ASI
{
	std::cout << "Form Copy Constructor!" << std::endl;
	*this = cpy;
}

Form::~Form( void )
{
	std::cout << "Form Destructor!" << std::endl;
}

Form & Form::operator=( Form & asg )
{
	if (this != &asg)
	{
		this->_isSigned = asg.getIsSigned();
		// Name & grades????
	}
	return *this;
}

std::string Form::getName( void ) const
{
	return this->_name;
}

int Form::getGradeSign( void ) const
{
	return this->_gradeSign;
}

int Form::getGradeExec( void ) const
{
	return this->_gradeExec;
}

bool Form::getIsSigned( void ) const
{
	return this->_isSigned;
}

void Form::beSigned( Bureaucrat *bur )
{
	if (bur->getGrade() > this->_gradeSign)
	{
		throw(GradeTooLowException());
	}
	else
	{
		this->_isSigned = true;
	}
}

std::ostream & operator<<( std::ostream & o, Form & rhs)
{
    std::cout << "Form " << rhs.getName();
	if (rhs.getIsSigned())
	{
		std::cout << " is signed!";
	}
	else
	{
		std::cout << " is not signed!";
	}
    return o;
}
