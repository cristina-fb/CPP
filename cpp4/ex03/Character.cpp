#include "Materia.hpp"
#include "Character.hpp"

Character::Character( void ): _name("Default")
{
    std::cout << "Character " << this->_name << " Constructor" << std::endl;
    for (int i = 0; i < 4; i++)
            this->inventory[i] = 0;
}

Character::Character( std::string name ): _name(name)
{
    std::cout << "Character " << this->_name << " Constructor" << std::endl;
    for (int i = 0; i < 4; i++)
            this->inventory[i] = 0;
}

Character::Character( Character & cpy )
{
    std::cout << "Character Copy Constructor" << std::endl;
    *this = cpy;
}

Character::~Character( void )
{
    std::cout << "Character " << this->_name << " Destructor" << std::endl;
    for (int i = 0; i < 4; i++)
            delete this->inventory[i];
}

Character & Character::operator=( Character & asg )
{
    if (*this != asg)
    {
        this->_name = asg.getName();
        for (int i = 0; i < 4; i++)
            this->inventory[i] = (asg.inventory[i])->clone();
    }
    return *this;
}

std::string const & getName() const
{
    return this->_name;
}

void equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == 0)
        {
            this->inventory[i] = m;
            return;
        }
    }
}

void unequip(int idx)
{
    if ((idx >= 0) && (idk < 4))
        this->_inventory[idx] = 0;
}

void use(int idx, ICharacter& target)
{
    if ((idx >= 0) && (idk < 4))
        (this->inventory[idx])->use(target);
}
