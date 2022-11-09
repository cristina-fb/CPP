/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:32:54 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 16:32:55 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP
# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice( void );
		Ice( Ice & cpy );
		~Ice( void );

		Ice & operator=( Ice & asg );

		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
