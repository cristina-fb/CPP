/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:13 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/20 17:29:34 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int sumar1(int a)
{
	return (a+1);
}

int main( void )
{
	char arr[3] = {'a', 'b', 'c'};

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	iter(arr, 3, &sumar1);
	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}
