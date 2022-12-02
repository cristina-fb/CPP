/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:17 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 16:58:28 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP
# include <iostream>

class Animal
{
	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal & src );
		virtual ~Animal( void );

		Animal & operator=( Animal & rhs );

		virtual void makeSound( void ) const;
		void setType( std::string myType);
		std::string getType( void ) const;

	protected:
		std::string type;
};
#endif
