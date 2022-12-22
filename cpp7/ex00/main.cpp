/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:24:02 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/22 12:20:55 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << std::endl << "---------- SWAP ----------" << std::endl;
	std::cout << "·INT" << std::endl;
	std::cout << "Before: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "After: a = " << a << ", b = " << b << std::endl;
	std::cout << "·STR" << std::endl;
	std::cout << "Before: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After: c = " << c << ", d = " << d << std::endl;
	
	std::cout << std::endl << "-------- MIN & MAX --------" << std::endl;
	std::cout << "·INT: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "·STR: c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
