/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:37:57 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/27 14:54:56 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	public:
		Array( void ): _arr(0), _n(0) { std::cout << "Array default constructor!" << std::endl; }
		Array( unsigned int n ): _n(n)
		{
			std::cout << "Array constructor!" << std::endl;
			this->_arr = new T[n];
			if (this->_arr)
			{
				for (unsigned int i = 0; i < n; i++)
				{
					this->_arr[i] = 0;
				}
			}
		}
		Array( Array & rhs ): _arr(0), _n(0)
		{
			std::cout << "Array copy constructor!" << std::endl;
			*this = rhs;
		}
		~Array( void )
		{
			std::cout << "Array destructor!" << std::endl;
			if (this->_arr != 0)
			{
				delete this->_arr;
			}
		}
		Array & operator=( Array & asg )
		{
			if (this != &asg)
			{
				if (this->_arr != 0)
				{
					delete this->_arr;
				}
				this->_n = asg.getSize();
				this->_arr = new T[this->_n];
				if (this->_arr)
				{
					for (unsigned int i = 0; i < this->_n; i++)
					{
						this->_arr[i] = asg[i];
					}
				}
			}
			return *this;
		}
		class wrongIndex: public std::exception
		{
			public:
				const char * what( void ) const throw()
				{
					return ("Index out of range :(");
				}
		};
		int getSize( void ) const { return this->_n; }
		T & operator[]( unsigned int i ) 
		{ 
			if ((i < 0) || (i > this->_n))
			{
				throw(wrongIndex());
			}
			return this->_arr[i];
		}
	
	private:
		T * _arr;
		unsigned int _n;
};
#endif
