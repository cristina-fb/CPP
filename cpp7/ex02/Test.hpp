/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:28:35 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 14:33:13 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CLASS_HPP
# define TEST_CLASS_HPP
# include <iostream>
class Test
{
    public:
        Test( void );
        Test( Test & cpy );
        Test( int n );
        ~Test( void );

        Test & operator=( Test & asg );
        int get( void ) const;
        void set( int a );
    
    private:
        int _n;
};
#endif
