/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:15:49 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 19:57:30 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main( void )
{
	std::list<int> lst;
	std::vector<int> v;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	std::cout << "------------------ LIST ------------------" << std::endl;
	try
	{
		easyfind(lst, 55);
	}
	catch(char const * str)
	{
		std::cout << str << std::endl;
	}
	try
	{
		easyfind(lst, 6);
	}
	catch(char const * str)
	{
		std::cout << str << std::endl;
	}
	std::cout << "------------------ VECTOR ------------------" << std::endl;
	try
	{
		easyfind(v, 55);
	}
	catch(char const * str)
	{
		std::cout << str << std::endl;
	}
	try
	{
		easyfind(v, 6);
	}
	catch(char const * str)
	{
		std::cout << str << std::endl;
	}
	return 0;
}
