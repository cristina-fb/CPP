/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:31:44 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/16 14:55:32 by crisfern         ###   ########.fr       */
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
    std::cout << std::endl << "------- CREATE BUREAUCRATS -------" << std::endl;
    Bureaucrat * ba = new Bureaucrat("A", 146);
    Bureaucrat * bb = new Bureaucrat("B", 142);
    Bureaucrat * bc = new Bureaucrat("C", 50);
    Bureaucrat * bd = new Bureaucrat("D", 20);
    Bureaucrat * be = new Bureaucrat("E", 2);
    std::cout << std::endl << "------- CREATE FORMS -------" << std::endl;
    ShrubberyCreationForm * form1 = new ShrubberyCreationForm("Home");
    RobotomyRequestForm * form2 = new RobotomyRequestForm("Paco");
    PresidentialPardonForm * form3 = new PresidentialPardonForm("Antonio");
    std::cout << std::endl << "------- A(146) CAN'T SIGN SHRUBBERYCREATION (145) -------" << std::endl;
    ba->signForm(form1);
    std::cout << std::endl << "------- C(50) CAN'T EXECUTE SHRUBBERYCREATION (137) -------" << std::endl;
    bc->executeForm(*form1);
    std::cout << std::endl << "------- B(142) CAN SIGN & CAN'T EXECUTE SHRUBBERYCREATION (145, 137) -------" << std::endl;
    bb->signForm(form1);
    bb->executeForm(*form1);
    std::cout << std::endl << "------- C(50) CAN EXECUTE SHRUBBERYCREATION (137) -------" << std::endl;
    bc->executeForm(*form1);

    std::cout << std::endl << "------- B(142) CAN'T SIGN ROBOTOMYREQUEST (72) -------" << std::endl;
    bb->signForm(form2);
    std::cout << std::endl << "------- D(20) CAN'T EXECUTE ROBOTOMYREQUEST (45) -------" << std::endl;
    bd->executeForm(*form2);
    std::cout << std::endl << "------- C(50) CAN SIGN & CAN'T EXECUTE ROBOTOMYREQUEST (72, 45) -------" << std::endl;
    bc->signForm(form2);
    bc->executeForm(*form2);
    std::cout << std::endl << "------- D(20) CAN EXECUTE ROBOTOMYREQUEST (45) -------" << std::endl;
    bd->executeForm(*form2);

    std::cout << std::endl << "------- C(50) CAN'T SIGN PRESIDENTIALPARDON (23) -------" << std::endl;
    bc->signForm(form3);
    std::cout << std::endl << "------- E(2) CAN'T EXECUTE PRESIDENTIALPARDON (5) -------" << std::endl;
    be->executeForm(*form3);
    std::cout << std::endl << "------- D(20) CAN SIGN & CAN'T EXECUTE PRESIDENTIALPARDON (23, 5) -------" << std::endl;
    bd->signForm(form3);
    bd->executeForm(*form3);
    std::cout << std::endl << "------- E(2) CAN EXECUTE PRESIDENTIALPARDON (5) -------" << std::endl;
    be->executeForm(*form3);

    std::cout << std::endl << "------- DELETE BUREAUCRATS -------" << std::endl;
    delete ba;
    delete bb;
    delete bc;
    delete bd;
    delete be;
    std::cout << std::endl << "------- DELETE FORMS -------" << std::endl;
    delete form1;
    delete form2;
    delete form3;
    std::cout << std::endl << "------- END -------" << std::endl;
    return 0;
}
