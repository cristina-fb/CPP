/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:18:34 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 14:03:59 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base *generate(void)
{
    Base *ptr = NULL;
    srand(time(NULL));
	int i = rand() % 3;
    if (i == 0)
    {
        ptr = new A();
        std::cout << "Created A!" << std::endl;
    }
    else if (i == 1)
    {
        ptr = new B();
        std::cout << "Created B!" << std::endl;
    }
    else
    {
        ptr = new C();
        std::cout << "Created C!" << std::endl;
    }
    return ptr;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "ᴬ" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Ç" << std::endl;
    }
    else
    {
        std::cout << "Derived class not identified :(" << std::endl;
    }
}
