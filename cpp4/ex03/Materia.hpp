#ifndef MATERIA_CLASS_HPP
# define MATERIA_CLASS_HPP
# include <iostream>

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