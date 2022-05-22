#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

class Zombie
{
    public:
        Zombie( void );
        ~Zombie( void );
        void announce (void) const;
        void set_name( std::string name);

    private:
        std::string _name;
};
#endif