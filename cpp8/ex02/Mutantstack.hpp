/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:21:15 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/24 12:33:36 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP
# include <stack>
template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack( void ) {}
		MutantStack( MutantStack & cpy ) { *this = cpy; }
		~MutantStack( void ) {}

		MutantStack & operator=( MutantStack & asg )
		{
			if (this != &asg)
			{
				this->c.clear();
				this->c = asg.c;
			}
			return *this; 
		}
		
		iterator begin( void ) { return this->c.begin(); }
		iterator end( void ) { return this->c.end(); }
};
#endif
