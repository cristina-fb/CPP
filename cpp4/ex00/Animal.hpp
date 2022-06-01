#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP
# include <iostream>

class Animal
{
	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal & src );
		~Animal( void );

		Animal & operator=( Animal & rhs );

		virtual void makeSound( void ) const;
		std::string getType( void ) const;

	protected:
		std::string type;
};
#endif
