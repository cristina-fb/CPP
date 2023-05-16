#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ): fnData(""), fnInput("")
{
}

BitcoinExchange::BitcoinExchange( std::string data, std::string input ): fnData(data), fnInput(input)
{
    std::ifstream dataStream;

    dataStream.open(this->fnData);
    for(std::string line; std::getline(dataStream, line);)
    {
        //add line to table
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
        this->fnInput = asg.fnInput;
        //copy of tables
    }
    return *this;
}

void BitcoinExchange::printResult( void )
{

}
