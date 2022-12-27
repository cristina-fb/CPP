/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:13 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/27 13:38:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int sum1(int a)
{
	return (a+1);
}
char touppercase(char a)
{
	if((a < 123) && (a > 96))
	{
		return (a-32);
	}
	return (a);
}

int main( void )
{
	char carr[3] = {'a', 'b', 'c'};
	int iarr[3] = {1, 2, 3};

	std::cout << "Uppercase to Char Array: " << std::endl;
	std::cout << "Before: " << carr[0] << carr[1] << carr[2] << std::endl;
	iter(carr, 3, &touppercase);
	std::cout << "After: " << carr[0] << carr[1] << carr[2] << std::endl;
	std::cout << "Sum 1 to Int Array: " << std::endl;
	std::cout << "Before: " << iarr[0] << iarr[1] << iarr[2] << std::endl;
	iter(iarr, 3, &sum1);
	std::cout << "After: " << iarr[0] << iarr[1] << iarr[2] << std::endl;
	return 0;
}
