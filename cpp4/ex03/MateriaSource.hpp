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
