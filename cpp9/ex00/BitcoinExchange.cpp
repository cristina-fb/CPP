#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ): fnData(""), delimiter('\0')
{
}

BitcoinExchange::BitcoinExchange( std::string data, char delimiter ): fnData(data), delimiter(delimiter)
{
    std::ifstream dataStream;
    std::string str;
    int i = 0;
    int n;

    dataStream.open(this->fnData);
    for(std::string line; std::getline(dataStream, line);)
    {
        n = line.find(this->delimiter);
        str = line.substr(n+1);
        if (i++)
            this->Data.insert(std::pair<std::string, double>(line.substr(0, n), std::atof(str.c_str())));
    }
    dataStream.close();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange & cpy )
{
    *this = cpy;
}

BitcoinExchange::~BitcoinExchange( void )
{
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange & asg )
{
    if( this != &asg)
    {
        this->fnData = asg.fnData;
        asg.Data.clear();
        //std::copy(this->Data.begin(), this->Data.end(), asg.Data.begin());
    }
    return *this;
}
