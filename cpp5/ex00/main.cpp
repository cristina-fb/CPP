#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{
    std::cout << "------- PACO (42) -------" << std::endl;
    Bureaucrat *paco = new Bureaucrat("Paco", 42);
    std::cout << *paco << std::endl;
    try
    {
        std::cout << "Increment grade: ";
        paco->incrementGrade();
        std::cout << *paco << std::endl;
        std::cout << "Decrement grade: ";
        paco->decrementGrade();
        std::cout << *paco << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    delete paco;
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
    return 0;
}
