#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>

class BitcoinExchange
{
    public:
        BitcoinExchange( void );
        BitcoinExchange( std::string str );
        BitcoinExchange( BitcoinExchange & cpy );
        ~BitcoinExchange( void );
        
        BitcoinExchange & operator=( BitcoinExchange & rhs );

        std::string strdate;
        int year;
        int month;
        int day;
        float value;
        bool validDate;
};
#endif
