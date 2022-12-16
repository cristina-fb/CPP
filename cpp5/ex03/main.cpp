/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:31:44 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/16 17:47:46 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void leaks( void )
{
    system("leaks -q Bureaucrat");
}

int main( void )
{
    atexit(leaks);

    Intern * me = new Intern();
    Bureaucrat * pepe = new Bureaucrat("Pepe", 3);

    std::cout << std::endl << "------- CREATE FORMS -------" << std::endl;
    Form * shrubbery = me->makeForm("shrubbery creation", "Home");
    Form * robotomy = me->makeForm("robotomy request", "Paco");
    Form * presidential = me->makeForm("presidential pardon", "Antonio");
    me->makeForm("hola caracola", "Juan");

    std::cout << std::endl << "------- SIGN & EXECUTE -------" << std::endl;
    pepe->signForm(shrubbery);
    pepe->executeForm(*shrubbery);
    pepe->signForm(robotomy);
    pepe->executeForm(*robotomy);
    pepe->signForm(presidential);
    pepe->executeForm(*presidential);
    std::cout << std::endl << "------- DELETES -------" << std::endl;
    delete me;
    delete pepe;
    delete shrubbery;
    delete robotomy;
    delete presidential;
    std::cout << std::endl << "------- END -------" << std::endl;
    return 0;
}
