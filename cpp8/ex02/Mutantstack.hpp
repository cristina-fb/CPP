/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:21:15 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/27 17:25:26 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP
class Mutantstack
{
	public:
		MutantStack( void );
		MutantStack( MutantStack & cpy );
		~MutantStack( void );

		MutantStack & operator=( MutantStack & asg );
};
#endif