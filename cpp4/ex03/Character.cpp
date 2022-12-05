/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:32:15 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/05 17:45:24 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ): _name("Default")
{
    std::cout << "Character " << this->_name << " constructor!" << std::endl;
    for (int i = 0; i < 4; i++)
            this->inventory[i] = 0;
}

Character::Character( std::string name ): _name(name)
{
    std::cout << "Character " << this->_name << " constructor!" << std::endl;
    for (int i = 0; i < 4; i++)
            this->inventory[i] = 0;
}

Character::Character( Character & cpy )
{
    std::cout << "Character copy constructor!" << std::endl;
    for (int i = 0; i < 4; i++)
            this->inventory[i] = 0;
    *this = cpy;
}

Character::~Character( void )
{
    std::cout << "Character " << this->_name << " destructor!" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != 0)
        {
            delete this->inventory[i];
        }
    }
}

Character & Character::operator=( Character & asg )
{
    if (this != &asg)
    {
        this->_name = asg.getName();
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i] != 0)
            {
                delete this->inventory[i];
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (asg.inventory[i] != 0)
            {
                this->inventory[i] = (asg.inventory[i])->clone();
            }
            else
            {
                this->inventory[i] = 0;
            }
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::setName(std::string const myName)
{
    this->_name = myName;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == 0)
        {
            this->inventory[i] = m;
            return;
        }
    }
    std::cout << "Not enough space on inventory :(" << std::endl;
}

void Character::unequip(int idx)
{
    if ((idx >= 0) && (idx < 4))
    {
        this->inventory[idx] = 0;
        return;
    }
    std::cout << "Index "<< idx << " not valid" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0) && (idx < 4))
    {
        if (this->inventory[idx] != 0)
        {
            (this->inventory[idx])->use(target);
            return;
        }
    }
    std::cout << "No Materia available in index " << idx << std::endl;
}
