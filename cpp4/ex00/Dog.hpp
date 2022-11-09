/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:53 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:00:54 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP
# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		Dog( Dog & src );
		~Dog( void );

		Dog & operator=( Dog & rhs );

		virtual void makeSound( void ) const;
};
#endif
