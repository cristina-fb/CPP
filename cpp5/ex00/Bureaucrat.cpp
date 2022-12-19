/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:00:37 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/19 12:39:46 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name(""), _grade(150)
{
    std::cout << "Bureaucrat default constructor!" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat &cpy ): _name(cpy.getName()), _grade(cpy.getGrade())
{
    std::cout << "Bureaucrat copy destructor!" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name), _grade(grade)
{   
    if (grade <= 0)
    {
        throw(Bureaucrat::GradeTooHighException());
    }
    else if (grade >= 151)
    {
        throw(Bureaucrat::GradeTooLowException());
    }
    else
    {
        std::cout << "Bureaucrat " << this->_name << " constructor!" << std::endl;
    }
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << "Bureaucrat " << this->_name << " destructor!" << std::endl;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat &asg )
{
    if (this != &asg)
    {
        this->_grade = asg.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName( void ) const
{
    return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade( void )
{
    if ((this->_grade - 1) <= 0)
    {
        throw(Bureaucrat::GradeTooHighException());
    }
    else
    {
        this->_grade--;
    }
}

void Bureaucrat::decrementGrade( void )
{
    if ((this->_grade + 1) >= 151)
    {
        throw(Bureaucrat::GradeTooLowException());
    }
    else
    {
        this->_grade++;
    }
}

std::ostream & operator<<( std::ostream & o, Bureaucrat & rhs)
{
    std::cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
