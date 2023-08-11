#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include "Date.hpp"

class BitcoinExchange
{
    public:
        BitcoinExchange( void );
        BitcoinExchange( BitcoinExchange & cpy );
        ~BitcoinExchange( void );
        
        BitcoinExchange & operator=( BitcoinExchange & rhs );
        double searchDate( Date date );

        std::map<Date*, double> data;
};
#endif
