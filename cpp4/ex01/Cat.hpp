/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:12:59 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:33:53 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( Cat & src );
		virtual ~Cat( void );

		Cat & operator=( Cat & rhs );

		void makeSound( void ) const;
		Brain *getCatBrain( void ) const;

	private:
		Brain* _catBrain;
};
#endif
