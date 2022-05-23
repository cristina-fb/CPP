#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap( std::string name);
        ScavTrap( ScavTrap & src );
        ~ScavTrap( void );

        ScavTrap & operator=( ScavTrap & src );

        void attack( std::string const & target );
        void guardGate( void );
};
#endif
