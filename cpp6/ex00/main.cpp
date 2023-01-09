/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:58:36 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/09 17:22:32 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int main ( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments!" << std::endl;
		return -1;
	}

	Converter *a = new Converter(argv[1]);
	delete a;
	return 0;
}
