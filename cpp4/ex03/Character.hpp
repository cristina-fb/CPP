/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:32:25 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/05 17:48:24 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP
# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
    public:
        Character( void );
        Character( std::string name );
        Character( Character & cpy );
        ~Character( void );

        Character & operator=( Character & asg );

		std::string const & getName() const;
        void setName(std::string const myName);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
        
        AMateria* inventory[4];

    private:
        std::string _name;
};
#endif
