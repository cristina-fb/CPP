#ifndef RPN_CLASS_H
# define RPN_CLASS_H
# include <iostream>
# include <cctype>
# include <stack>
# include <sstream>
# include <string>
#endif

class RPN
{
    public:
        RPN( void );
        RPN( std::string str );
        RPN( RPN & cpy );
        ~RPN( void );

        RPN & operator=( RPN & asg );

        std::string getStr( void ) const;
        int getRes( void ) const;

        void add( void );
        void sub( void );
        void mul( void );
        void div( void );

    private:
        std::string _str;
        std::stack<int> _s;
};
