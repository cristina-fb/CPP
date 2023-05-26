#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange( void );
        BitcoinExchange( std::string data, char delimiter );
        BitcoinExchange( BitcoinExchange & cpy );
        ~BitcoinExchange( void );
        
        BitcoinExchange & operator=( BitcoinExchange & rhs );

        std::string fnData;
        char delimiter;
        std::multimap<std::string, double> Data;
};
#endif
