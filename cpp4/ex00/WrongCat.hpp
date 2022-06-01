#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( WrongCat & src );
		~WrongCat( void );

		WrongCat & operator=( WrongCat & rhs );

		void makeSound( void ) const;
};
#endif
