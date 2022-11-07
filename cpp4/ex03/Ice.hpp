#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP
# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice( void );
		Ice( Ice & cpy );
		~Ice( void );

		Ice & operator=( Ice & asg );

		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
