/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:54 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/19 16:51:06 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <algorithm>
#include <time.h>
#include "span.hpp"

void print(int x)
{
    std::cout << x << std::endl;
}

int main()
{
    std::list<int> lst, sp;
    srand(time(NULL));
    lst.assign(10000, rand());
    span tab(10000);
    tab.addNumber(11);
    tab.addNumber(12);
    tab.addNumber(13);
    tab.addNumber(14);
    tab.addNumber(15);
    try
    {
        tab.addNumber(lst.begin(), lst.end());
    }
    catch(const char * str)
    {
        std::cerr << str << std::endl;
    }
    sp = tab.getTab();
    std::for_each(sp.begin(), sp.end(), print);
    std::cout << "Longest Span: " << tab.longestSpan() << std::endl;
    std::cout << "Shortest Span: " << tab.shortestSpan() << std::endl;
    return 0;
}
