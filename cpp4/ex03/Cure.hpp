#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure( void );
		Cure( Cure & cpy );
		~Cure( void );

		Cure & operator=( Cure & asg );

		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
