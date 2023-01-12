/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:54 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/12 17:42:36 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

void print(int a)
{
    std::cout << a << std::endl;
}

int main()
{
    std::list<int> tab, tab2;
    tab.push_back(10);
    tab.push_back(7);
    tab.push_back(5);
    tab.push_back(4);
    tab.push_back(8);
    tab2 = tab;
    //std::adjacent_difference(tab.begin(), tab.end(), tab.begin());
    std::for_each(tab2.begin(), tab2.end(), print);
    return 0;
}
