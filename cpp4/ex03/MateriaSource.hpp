/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:50:54 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 16:50:55 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource( void );
        MateriaSource( MateriaSource & cpy);
        ~MateriaSource( void );

        MateriaSource & operator=(MateriaSource & asg);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);

        AMateria *list[4];
};
#endif
