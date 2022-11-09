/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:50:36 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 16:50:49 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    std::cout << "MateriaSource Constructor" << std::endl;
    for (int i = 0; i < 4; i++)
            this->list[i] = 0;
}

MateriaSource::MateriaSource( MateriaSource & cpy)
{
    std::cout << "MateriaSource copy Constructor" << std::endl;
    *this = cpy;
}

MateriaSource::~MateriaSource( void )
{
    std::cout << "MateriaSource Destructor" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->list[i] != 0)
            delete this->list[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource & asg)
{
    if (this != &asg)
    {
        for (int i = 0; i < 4; i++)
            list[i] = (asg.list[i])->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->list[i] == 0)
        {
            this->list[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if ((this->list[i])->getType() == type)
            return (this->list[i])->clone();
    }
    return 0;
}
