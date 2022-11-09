/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:12:43 by crisfern          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:45 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP
# include <iostream>

class Brain
{
	public:
		Brain( void );
		Brain( Brain & src );
		~Brain( void );

		Brain & operator=( Brain & rhs );

		std::string* get_ideas( void );
		void set_ideas( std::string myidea );
		int get_n_ideas( void );

	private:
		int _n_ideas;
		std::string _ideas[100];
};
#endif
