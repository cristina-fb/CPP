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
    *this = cpy
}

MateriaSource::~MateriaSource( void )
{
    std::cout << "MateriaSource cDestructor" << std::endl;
    for (int i = 0; i < 4; i++)
            delete this->list[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource & asg)
{
    if (*this != asg)
    {
        for (int i = 0; i < 4; i++)
            list[i] = (asg.inventory[i])->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria*)
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
        if ((this->list[i])->getName() == type)
            return (this->list[i])->clone();
    }
    return 0;
}
