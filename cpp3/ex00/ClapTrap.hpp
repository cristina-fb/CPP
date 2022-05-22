#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H
# include <iostream>

class ClapTrap
{
    public:
        ClapTrap( void );
        ClapTrap( std::string name);
        ClapTrap( ClapTrap & src );
        ~ClapTrap( void );

        ClapTrap & operator=( ClapTrap & src );

        void attack( std::string const & target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );

        int getHitpoints( void );
        int getEnergypoints( void );
        int getDamage( void );
        std::string getName( void );

    private:
        std::string _name;
        int _hitpoints;
        int _energypoints;
        int _damage;
};
#endif
