/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:37:57 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 14:50:57 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	public:
		Array( void ): _arr(0), _n(0) {}
		Array( unsigned int n ): _n(n)
		{
			this->_arr = new T[n];
		}
		Array( Array & rhs ): _arr(0), _n(0)
		{
			*this = rhs;
		}
		~Array( void )
		{
			if (this->_arr != 0)
				delete [] this->_arr;
		}
		Array & operator=( Array & asg )
		{
			if (this != &asg)
			{
				if (this->_arr != 0)
					delete [] this->_arr;
				this->_n = asg.size();
				this->_arr = new T[this->_n];
				if (this->_arr)
				{
					for (unsigned int i = 0; i < this->_n; i++)
						this->_arr[i] = asg[i];
				}
			}
			return *this;
		}
		int size( void ) const { return this->_n; }
		T & operator[]( unsigned int i ) 
		{ 
			if ((i < 0) || (i > this->_n - 1))
				throw(wrongIndex());
			return this->_arr[i];
		}
		
		class wrongIndex: public std::exception
		{
			public:
				const char * what( void ) const throw()
				{
					return ("Index out of range :(");
				}
		};
	
	private:
		T * _arr;
		unsigned int _n;
};
#endif
