#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( Cat & src );
		~Cat( void );

		Cat & operator=( Cat & rhs );

		virtual void makeSound( void ) const;
		Brain *getCatBrain( void ) const;

	private:
		Brain* catBrain;
};
#endif
