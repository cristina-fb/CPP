/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:01:03 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/13 19:26:35 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP
# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm & cpy );
		~ShrubberyCreationForm( void );
		
		ShrubberyCreationForm & operator=(ShrubberyCreationForm & asg);
		
		std::string getTarget( void ) const;
		void execute( Bureaucrat const & executor ) const;

	private:
		std::string _target;
};
#endif
