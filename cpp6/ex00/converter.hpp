/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:03:08 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 17:59:01 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_CLASS_HPP
# define CONVERTER_CLASS_HPP
# include <iostream>
# include <stdlib.h>

class Converter
{
	public:
		Converter( void );
		Converter( std::string str );
		Converter( Converter & cpy );
		~Converter ( void );

		Converter & operator=( Converter & asg );
		void convert( void );

		int getType( void ) const;
		char getC( void ) const;
		int getI( void ) const;
		float getF( void ) const;
		double getD( void ) const;
	
	private:
		int _type;
		char _c;
		int	_i;
		float _f;
		double _d;
};
std::ostream & operator<<( std::ostream & o, Converter & rhs);
#endif
