#include "BitcoinExchange.hpp"

static void init(BitcoinExchange *btc)
{
    btc->strdate = "";
    btc->year = -1;
    btc->month = -1;
    btc->day = -1;
    btc->value = -1;
    btc->validDate = false;
}

BitcoinExchange::BitcoinExchange( void )
{
    init(this);
}

BitcoinExchange::BitcoinExchange( std::string str )
{
    std::cout << str << std::endl;
    
    // this->strdate = ;
    // this->value = ;
    // this->year = ;
    // this->month = ;
    // this->day = ;
    // this->validDate = ;
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
        this->strdate = asg.strdate;
        this->year = asg.year;
        this->month = asg.month;
        this->day = asg.day;
        this->value = asg.value;
        this->validDate = asg.validDate;
    }
    return *this;
}
