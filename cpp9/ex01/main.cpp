/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:18 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/06 15:06:19 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return (0);
    }
    try
    {
        RPN a(argv[1]);
        std::cout << a.getRes() << std::endl;
    }
    catch(char const * exc)
    {
        std::cout << exc << std::endl;
    }
    return (0);
}
