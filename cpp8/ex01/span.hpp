/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:37 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/27 17:11:34 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP
# include <iostream>
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
		unsigned int getN( void ) const;

	private:
		unsigned int _N;
};
#endif