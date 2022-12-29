/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:18:34 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/29 16:18:25 by crisfern         ###   ########.fr       */
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
    }
    else if (i == 1)
    {
        ptr = new B();
    }
    else
    {
        ptr = new C();
    }
    return ptr;
}

void identify(Base *p)
{
    A *a = reinterpret_cast<A*>(p);
    B *b = reinterpret_cast<B*>(p);
    C *c = reinterpret_cast<C*>(p);
    std::cout << a << b << c << std::endl;
}
