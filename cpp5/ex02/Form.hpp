/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:29:01 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/13 18:39:03 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form( void );
		Form( std::string name, int gradeSign, int gradeExec );
		Form( Form & cpy );
		virtual ~Form( void );

		Form & operator=( Form & asg );

		class GradeTooHighException: public std::exception
		{
			public:
				const char * what( void ) const throw()
				{
					return("grade too high :(");
				}
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				const char * what( void ) const throw()
				{
					return("grade too low :(");
				}
		};

		std::string getName( void ) const;
		int getGradeSign( void ) const;
		int getGradeExec( void ) const;
		bool getIsSigned( void ) const;
		void beSigned( Bureaucrat *bur );
		virtual void execute( Bureaucrat const & executor ) const = 0;

	private:
		const std::string _name;
		const int _gradeSign;
		const int _gradeExec;
		bool _isSigned;
};
std::ostream & operator<<( std::ostream & o, Form & rhs);

#endif
