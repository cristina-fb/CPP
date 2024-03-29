/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:01:16 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/02 17:09:50 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal & src );
		~WrongAnimal( void );

		WrongAnimal & operator=( WrongAnimal & rhs );

		void makeSound( void ) const;
		void setType( std::string myType );
		std::string getType( void ) const;

	protected:
		std::string type;
};
#endif
