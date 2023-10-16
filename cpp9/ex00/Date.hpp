/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:05:42 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 17:18:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_CLASS_HPP
# define DATE_CLASS_HPP
# include <iostream>

class Date
{
    public:
        Date( std::string str );
        Date( Date & cpy );
        ~Date( void );

        Date & operator=( Date & asg );

        int year;
        int month;
        int day;
        bool isValid;
        std::string dstr;

    private:
        Date( void );
};
#endif
