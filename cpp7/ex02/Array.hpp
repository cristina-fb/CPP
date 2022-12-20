/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:37:57 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/20 17:50:50 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP //RECORDAR PROTEGER LOS HPP
# define ARRAY_HPP
template<typename T>
class Array
{
	public:
		Array( void )
		{
		}
		Array( unsigned int n );
		{
		}
		Array( Array & rhs );
		{
		}
		~Array( void );
		{
		}

		Array & operator=( Array & asg );
		{
		}
		int getSize( void ) const;
		{
		}
		T * getArr( void ) const { return this->_arr; }
	
	private:
		T * _arr;
};
#endif