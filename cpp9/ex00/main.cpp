/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:05:27 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/06 15:05:30 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"
#include "Date.hpp"

void leaks(void)
{
    system("leaks -q btc");
}

int main(int argc, char **argv)
{
    atexit(leaks);
    if (argc < 2)
        std::cout << "Error: could not open file." << std::endl;
    else if (argc > 3)
        std::cout << "Error: invalid number of arguments." << std::endl;
    else
    {
        try
        {
            BitcoinExchange *data = new BitcoinExchange();
            BitcoinExchange a(*data);
            delete data;
            a.printInputResult(argv[1]);
        }
        catch(const char * exc)
        {
            std::cerr << exc << std::endl;;
        }
        
    }
    return (0); 
}
