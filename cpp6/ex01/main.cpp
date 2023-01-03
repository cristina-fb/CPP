/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:10:16 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 15:02:20 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "functions.hpp"

int main(void)
{
    Data *a = new Data("Hola Caracola");
    std::cout << a->getStr() << std::endl;
    std::cout << a << std::endl;
    uintptr_t ptr = serialize(a);
    std::cout << ptr << std::endl;
    Data *b = deserialize(ptr);
    std::cout << b->getStr() << std::endl;
    std::cout << b << std::endl;
    return 0;
}
