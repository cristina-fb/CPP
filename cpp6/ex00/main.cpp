/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:58:36 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/20 12:14:42 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void charConvertion( std::string str )
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
}

int main ( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments!" << std::endl;
		return -1;
	}
	std::cout << "char: '";
	charConvertion(argv[1]);
	std::cout << "'" << std::endl;
	std::cout << "int: ";
	intConvertion(argv[1]);
	std::cout << std::endl;
	std::cout << "float: ";
	floatConvertion(argv[1]);
	std::cout << std::endl;
	std::cout << "double: ";
	doubleConvertion(argv[1]);
	std::cout << std::endl;
	return 0;
}
