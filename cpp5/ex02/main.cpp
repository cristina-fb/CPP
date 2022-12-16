/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:31:44 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/16 12:31:05 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void leaks( void )
{
    system("leaks -q Bureaucrat");
}

int main( void )
{
    atexit(leaks);
    Bureaucrat * paco = new Bureaucrat("Paco", 42);
    ShrubberyCreationForm * form1 = new ShrubberyCreationForm("Antonio");
    paco->executeForm(*form1);
    delete form1;
    delete paco;
    std::cout << std::endl << "------- END -------" << std::endl;
    return 0;
}
