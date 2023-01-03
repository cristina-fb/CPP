/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:12:11 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 14:07:26 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <iostream>

int main()
{
    Base *base = new Base();
    Base *derived = generate();
    identify(derived);
    identify(base);
    identify(NULL);
    delete base;
    delete derived;
    return 0;
}
