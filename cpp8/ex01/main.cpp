/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:54 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/16 18:37:42 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <algorithm>
#include "span.hpp"

int main()
{
    span tab(5);
    tab.addNumber(-10);
    tab.addNumber(7);
    tab.addNumber(-5);
    tab.addNumber(19);
    tab.addNumber(-3);
    std::cout << tab.shortestSpan() << std::endl;
    return 0;
}
