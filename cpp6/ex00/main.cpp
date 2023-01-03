/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:58:36 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 17:34:02 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

/*void charConvertion( std::string str )
{
	try
	{
		int n = std::stoi(str, NULL, 10);
		std::cout << (char)n;
	}
	catch( std::exception & e )
	{
		(void)e;
		std::cout << "not convertible: ";
	}
}

void intConvertion( std::string str )
{
	try
	{
		int n = std::stoi(str, NULL, 10);
		std::cout << n;
	}
	catch( std::exception & e )
	{
		(void)e;
		std::cout << "not convertible: ";
	}
}

void floatConvertion( std::string str )
{
	try
	{
		float n = std::stof(str, NULL);
		std::cout << n;
	}
	catch( std::exception & e )
	{
		(void)e;
		std::cout << "not convertible: ";
	}
}

void doubleConvertion( std::string str )
{
	try
	{
		double n = std::stod(str, NULL);
		std::cout << n;
	}
	catch( std::exception & e )
	{
		(void)e;
		std::cout << "not convertible: ";
	}
}*/

int main ( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments!" << std::endl;
		return -1;
	}

	Converter *a = new Converter(argv[1]);
	a->convert();
	std::cout << *a << std::endl;
	return 0;
}
