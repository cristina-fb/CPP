/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:01:32 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:01:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( WrongCat & src );
		~WrongCat( void );

		WrongCat & operator=( WrongCat & rhs );

		void makeSound( void ) const;
};
#endif
