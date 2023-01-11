/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:15:49 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 19:51:06 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include "easyfind.hpp"

int main( void )
{
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
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
	return 0;
}
