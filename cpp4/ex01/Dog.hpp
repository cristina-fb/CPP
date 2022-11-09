/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:13:29 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:13:30 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		Dog( Dog & src );
		virtual ~Dog( void );

		Dog & operator=( Dog & rhs );

		void makeSound( void ) const;
		Brain *get_DogBrain( void ) const;

	private:
		Brain* _dogBrain;
};
#endif
