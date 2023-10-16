/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:29 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:54 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_H
# define RPN_CLASS_H
# include <iostream>
# include <stack>
# include <string>
# include <limits>
#endif

class RPN
{
    public:
        RPN( std::string const &str );
        RPN( RPN const &cpy );
        ~RPN( void );

        RPN & operator=( RPN const &asg );

        std::string getStr( void ) const;
        std::stack<long int> getStack( void ) const;
        int getRes( void ) const;

        void add( void );
        void sub( void );
        void mul( void );
        void div( void );

    private:
        RPN( void );
        
        std::string _str;
        std::stack<long int> _s;
};
