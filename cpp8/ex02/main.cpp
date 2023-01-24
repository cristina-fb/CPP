/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:21:12 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/24 12:36:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::cout << "Push 5" << std::endl;
	mstack.push(5);
	std::cout << "Push 17" << std::endl;
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Pop" << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Push 3" << std::endl;
	mstack.push(3);
	std::cout << "Push 5" << std::endl;
	mstack.push(5);
	std::cout << "Push 737" << std::endl;
	mstack.push(737);
	std::cout << "Push 0" << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "- STACK - " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Top copy stack: " << s.top() << std::endl;
	MutantStack<int> stack2;
	std::cout << "Push 1" << std::endl;
	stack2.push(1);
	std::cout << "Push 2" << std::endl;
	stack2.push(2);
	std::cout << "Push 3" << std::endl;
	stack2.push(3);
	it = stack2.begin();
	ite = stack2.end();
	std::cout << "- STACK 2 - " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	stack2 = mstack;
	std::cout << "Stack2 = mstack" << std::endl;
	it = stack2.begin();
	ite = stack2.end();
	std::cout << "- STACK 2 - " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}
