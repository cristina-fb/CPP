/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:26 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/13 18:08:41 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        std::string getName( void ) const;
        int getGrade( void ) const;
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
