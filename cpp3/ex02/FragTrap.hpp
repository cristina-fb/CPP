#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap( void );
        FragTrap( std::string name);
        FragTrap( FragTrap & src );
        ~FragTrap( void );

        FragTrap & operator=( FragTrap & src );

        void attack( std::string const & target );
        void highFivesGuys( void );
};
#endif
