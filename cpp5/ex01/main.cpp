/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:31:44 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/19 12:56:18 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void leaks( void )
{
    system("leaks -q Bureaucrat");
}

int main( void )
{
    atexit(leaks);
    std::cout << std::endl << "------- INVALID FORM GRADES -------" << std::endl;
    try
    {
        Form *res = new Form("Resolution", 0, 50);
        std::cout << *res << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form *res = new Form("Resolution", 50, 0);
        std::cout << *res << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form *res = new Form("Resolution", 200, 50);
        std::cout << *res << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form *res = new Form("Resolution", 50, 200);
        std::cout << *res << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << std::endl << "------- PACO (50) CAN'T SIGN 42 FORM -------" << std::endl;
    Form * app = new Form("application", 42, 24);
    Bureaucrat * paco = new Bureaucrat("Paco", 50);
    paco->signForm(app);
    std::cout << *app << std::endl;


    std::cout << std::endl << "------- PEPE(35) CAN SIGN 42 FORM -------" << std::endl;
    Bureaucrat * pepe = new Bureaucrat("Pepe", 35);
    pepe->signForm(app);
    std::cout << *app << std::endl;
    
    std::cout << std::endl << "------- DESTRUCTORS -------" << std::endl;
    delete paco;
    delete pepe;
    delete app;
    std::cout << std::endl << "------- END -------" << std::endl;
    return 0;
}
