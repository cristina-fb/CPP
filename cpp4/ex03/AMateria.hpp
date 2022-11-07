#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( AMateria & cpy );
		~AMateria( void );

		AMateria & operator=( AMateria & asg );

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif
