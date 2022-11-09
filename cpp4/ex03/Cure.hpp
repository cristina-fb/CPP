/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:32:37 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 18:01:22 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure( void );
		Cure( Cure & cpy );
		~Cure( void );

		Cure & operator=( Cure & asg );
 
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
