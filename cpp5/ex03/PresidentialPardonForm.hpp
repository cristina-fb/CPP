/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:00:36 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/13 18:39:24 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP
# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm & cpy );
		~PresidentialPardonForm( void );
		
		PresidentialPardonForm & operator=(PresidentialPardonForm & asg);
		
		std::string getTarget( void ) const;
		void execute( Bureaucrat const & executor ) const;

	private:
		std::string _target;
};
#endif
