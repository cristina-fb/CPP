#ifndef DATE_CLASS_HPP
# define DATE_CLASS_HPP
# include <iostream>

class Date
{
    public:
        Date( void );
        Date( std::string str );
        Date( Date & cpy );
        ~Date( void );

        bool dateBefore( Date date );
        Date & operator=( Date & asg );

        int year;
        int month;
        int day;
        bool isValid;
};
#endif
