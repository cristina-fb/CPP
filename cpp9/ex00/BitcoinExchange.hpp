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
        BitcoinExchange( BitcoinExchange & cpy );
        ~BitcoinExchange( void );
        
        BitcoinExchange & operator=( BitcoinExchange & rhs );
        double searchDateValue( Date date );
        void printInputResult( std::string filename );

        std::map<Date*, double> data;
};
#endif
