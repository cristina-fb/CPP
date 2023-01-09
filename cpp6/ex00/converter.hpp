/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:03:08 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/09 16:29:34 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_CLASS_HPP
# define CONVERTER_CLASS_HPP
# include <iostream>
# include <iomanip>
# include <cctype>
# include <sstream>
# include <limits>
# define INT_MAX_F static_cast<float>(INT_MAX)
# define INT_MIN_F static_cast<float>(INT_MIN) - 1.0
# define INT_MAX_D static_cast<double>(INT_MAX) + 1.0
# define INT_MIN_D static_cast<double>(INT_MIN) - 1.0
# define FLOAT_MAX static_cast<double>(std::numeric_limits<float>::max())
# define FLOAT_MIN -static_cast<double>(std::numeric_limits<float>::max())

class Converter
{
	public:
		Converter( void );
		Converter( std::string str );
		Converter( Converter & cpy );
		~Converter ( void );

		Converter & operator=( Converter & asg );
		void convert( void );

		std::string getStr( void ) const;
		int getType( void ) const;
		char getC( void ) const;
		int getI( void ) const;
		float getF( void ) const;
		double getD( void ) const;

	private:
		std::string _str;
		int _type;
		char _c;
		int _i;
		float _f;
		double _d;
};
#endif
