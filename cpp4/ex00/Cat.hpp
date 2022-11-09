/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:36 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:00:38 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP
# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( Cat & src );
		~Cat( void );

		Cat & operator=( Cat & rhs );

		virtual void makeSound( void ) const;
};
#endif
