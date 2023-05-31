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
        BitcoinExchange( std::string data, char delimiter, int input );
        BitcoinExchange( BitcoinExchange & cpy );
        ~BitcoinExchange( void );
        
        BitcoinExchange & operator=( BitcoinExchange & rhs );
        bool isValidDate( std::string date );

        std::string fnData;
        char delimiter;
        int input;
        std::multimap<std::string, double> Data;
};
#endif
