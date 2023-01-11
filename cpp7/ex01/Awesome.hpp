/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:02:05 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 12:15:50 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_CLASS_HPP
# define AWESOME_CLASS_HPP
# include <iostream>
class Awesome
{
    public:
        Awesome( void );
        Awesome( Awesome & cpy );
        ~Awesome( void );
        Awesome & operator=( Awesome & asg );
        int get( void ) const;
    private:
        int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs );
#endif
