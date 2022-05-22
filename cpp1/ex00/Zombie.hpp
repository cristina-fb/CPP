#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

class Zombie
{
    public:
        Zombie( std::string name );
        ~Zombie( void );
        void announce (void);

    private:
        std::string _name;
};
#endif