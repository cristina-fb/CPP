/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:35:36 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 14:53:29 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_CLASS_HPP
# define DATA_CLASS_HPP
# include <iostream>
class Data
{
    public:
        Data( void );
        Data( std::string str );
        Data( Data & cpy );
        ~Data( void );

        Data & operator=( Data & asg );
        std::string getStr( void ) const;
    
    private:
        std::string _str;
};
#endif
