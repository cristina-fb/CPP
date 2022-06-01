#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal & src );
		~WrongAnimal( void );

		WrongAnimal & operator=( WrongAnimal & rhs );

		void makeSound( void ) const;
		std::string getType( void ) const;

	protected:
		std::string type;
};
#endif
