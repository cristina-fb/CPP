#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP
# include <iostream>
# include <exception>

class Bureaucrat
{
    public:
        Bureaucrat( void );
        Bureaucrat( Bureaucrat &cpy );
        Bureaucrat( std::string name, int grade );
        ~Bureaucrat( void );

        Bureaucrat & operator=( Bureaucrat &asg );

        std::string getName( void );
        int getGrade( void );
        void incrementGrade( void );
        void decrementGrade( void );

        class GradeTooHighException: public std::exception
        {
            public:
                const  char *  what ( void )  const  throw ()
                {
                    return ("Error! Grade too high!");
                }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                const  char *  what ( void )  const  throw ()
                {
                    return ("Error! Grade too low!");
                }
        };

    private:
        const std::string _name;
        int _grade;
};
std::ostream & operator<<( std::ostream & o, Bureaucrat & rhs);
#endif
