/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:05:51 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 16:22:56 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include "Date.hpp"
# define E1 "Error: bad input"
# define E2 "Error: not a positive number"
# define E3 "Error: too large a number"

class BitcoinExchange
{
    public:
        BitcoinExchange( void );
        BitcoinExchange( std::string dbfilename );
        BitcoinExchange( BitcoinExchange & cpy );
        ~BitcoinExchange( void );
        
        BitcoinExchange & operator=( BitcoinExchange & rhs );
        double searchDateValue( Date date );
        void printInputResult( std::string filename );

        std::map<Date*, double> data;
};
#endif
