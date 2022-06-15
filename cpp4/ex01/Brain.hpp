#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP
# include <iostream>

class Brain
{
	public:
		Brain( void );
		Brain( Brain & src );
		~Brain( void );

		Brain & operator=( Brain & rhs );

		std::string ideas[100];
};
#endif
