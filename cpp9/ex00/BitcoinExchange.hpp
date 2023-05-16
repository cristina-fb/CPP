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
        BitcoinExchange( std::string data, std::string input );
        BitcoinExchange( BitcoinExchange & cpy );
        ~BitcoinExchange( void );
        
        BitcoinExchange & operator=( BitcoinExchange & rhs );
        void printResult( void );

        std::string fnData;
        std::string fnInput;
        std::map<std::string, double> tData;
        std::map<std::string, double> tInput;
};
#endif
