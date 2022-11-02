#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		Dog( Dog & src );
		~Dog( void );

		Dog & operator=( Dog & rhs );

		void makeSound( void ) const;
		Brain *get_DogBrain( void ) const;

	private:
		Brain* _dogBrain;
};
#endif
