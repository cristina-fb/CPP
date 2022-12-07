/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:31:44 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/07 11:56:42 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void leaks( void )
{
    system("leaks -q Bureaucrat");
}

int main( void )
{
    atexit(leaks);
    std::cout << std::endl;
    std::cout << "------- PACO (42) -------" << std::endl;
    Bureaucrat *paco = new Bureaucrat("Paco", 42);
    std::cout << *paco << std::endl;
    try
    {
        std::cout << "Increment grade: ";
        paco->incrementGrade();
        std::cout << *paco << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Decrement grade: ";
        paco->decrementGrade();
        std::cout << *paco << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "------- PACA (1) -------" << std::endl;
    Bureaucrat *paca = new Bureaucrat("Paca", 1);
    std::cout << *paca << std::endl;
    try
    {
        std::cout << "Increment grade: ";
        paca->incrementGrade();
        std::cout << *paca << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    delete paca;
    std::cout << std::endl;
    std::cout << "------- PAQUI (150) -------" << std::endl;
    Bureaucrat *paqui = new Bureaucrat("Paqui", 150);
    std::cout << *paqui << std::endl;
    try
    {
        std::cout << "Decrement grade: ";
        paqui->decrementGrade();
        std::cout << *paqui << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    delete paqui;
    std::cout << std::endl;
    std::cout << "------- PEPE (151) -------" << std::endl;
    try
    {
        Bureaucrat *pepe = new Bureaucrat("Pepe", 151);
        std::cout << *pepe << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "------- PEPE (0) -------" << std::endl;
    try
    {
        Bureaucrat *pepe = new Bureaucrat("Pepe", 0);
        std::cout << *pepe << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "------- PEPE (-42) -------" << std::endl;
    try
    {
        Bureaucrat *pepe = new Bureaucrat("Pepe", -42);
        std::cout << *pepe << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "------- PEPE = PACO -------" << std::endl;
    Bureaucrat *pepe = new Bureaucrat("Pepe", 24);
    std::cout << *pepe << std::endl;
    *pepe = *paco;
    std::cout << *pepe << std::endl;
    delete paco;
    delete pepe;
    std::cout << "------- END -------" << std::endl;
    return 0;
}
