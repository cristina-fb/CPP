/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:42 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 14:54:29 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    std::list<int>  lst;
    std::vector<int>  vct;
    std::clock_t init_lst, init_vct, time_lst, time_vct;
    int n = 0;

    if (argc < 2)
        return (0);
    try
    {
        init_lst = std::clock();
        PmergeMe    a(argv, argc, 0);
        time_lst = (std::clock() - init_lst) * 1000000 / CLOCKS_PER_SEC;

        init_vct = std::clock();
        PmergeMe    b(argv, argc, 1);
        time_vct = (std::clock() - init_vct) * 1000000 / CLOCKS_PER_SEC;

        // PRINT VALUES
        std::cout << "Before        : ";
        for (int i = 1; i < argc; i++)
        {
            if (*argv[i])
            {
                std::cout << argv[i] << " ";
                n++;
            }
        }
        std::cout << std::endl;

        std::cout << "After   (list): ";
        a.printList();
        std::cout << "After (vector): ";
        b.printVector();
        std::cout << "Time to process a range of " << n << " elements with std::list : " << time_lst << " us" << std::endl;
        std::cout << "Time to process a range of " << n << " elements with std::vector : " << time_vct << " us" << std::endl;
    }
    catch(char const * exc)
    {
        std::cerr << exc << '\n';
    }
    return (0);
}
