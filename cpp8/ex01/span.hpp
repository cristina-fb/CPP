/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:37 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/16 17:39:38 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP
# include <iostream>
# include <list>
# include <exception>
# include <algorithm>
# include <numeric>
class span
{
	public:
		span( void );
		span( unsigned int N );
		span( span & cpy );
		~span( void );

		span & operator=( span & asg );
		void addNumber( int number );
		int shortestSpan( void ) const;
		int longestSpan( void ) const;
		std::list<int> getTab( void ) const;
		unsigned int getN( void ) const;

	private:
		std::list<int> _tab;
		unsigned int _n;
};
#endif
