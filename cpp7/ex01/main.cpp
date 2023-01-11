/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:13 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 12:22:21 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "Awesome.hpp"

template< typename T >
void print( T const & x )
{ 
	std::cout << x << std::endl;
	return; 
}

int main( void )
{
	Awesome tab[5];
	char carr[5] = {'a', 'b', 'c', 'd', 'e'};
	int iarr[5] = {0, 1, 2, 3, 4};
	std::cout << "Print Char Array: " << std::endl;
	iter(carr, 5, print<char>);
	std::cout << "Print Int Array: " << std::endl;
	iter(iarr, 5, print<int>);
	std::cout << "Print Awesome Array: " << std::endl;
	iter(tab, 5, print<Awesome>);
	return 0;
}
