#include "BitcoinExchange.hpp"

bool isStringDigit(std::string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(str.c_str()[i]))
            return (false);
    }
    return (true);
}

BitcoinExchange::BitcoinExchange( void ): fnData(""), delimiter('\0')
{
}

BitcoinExchange::BitcoinExchange( std::string data, char delimiter, int input): fnData(data), delimiter(delimiter), input(input)
{
    std::ifstream dataStream;
    std::string str;
    int i = 0;
    int pos;
    double n;

    dataStream.open(this->fnData);
    for(std::string line; std::getline(dataStream, line);)
    {
        pos = line.find(this->delimiter);
        str = line.substr(pos+1);
        if (i++)
        {
            n = std::atof(str.c_str());
            if (this->input)
            {
                if (pos == -1)
                    this->Data.insert(std::pair<std::string, double>(line, -1));
                else if (!this->isValidDate(line.substr(0, pos)))
                    this->Data.insert(std::pair<std::string, double>(line.substr(0, pos), -1));
                else if (n < 0)
                    this->Data.insert(std::pair<std::string, double>(line.substr(0, pos), -2));
                else if (n > 1000)
                    this->Data.insert(std::pair<std::string, double>(line.substr(0, pos), -3));
                else if (n == 0)
                    this->Data.insert(std::pair<std::string, double>(line.substr(0, pos), -4));
                else
                    this->Data.insert(std::pair<std::string, double>(line.substr(0, pos), n));
            }
            else
                this->Data.insert(std::pair<std::string, double>(line.substr(0, pos), n));
        }
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

bool BitcoinExchange::isValidDate( std::string date)
{
    int year;
    int month;
    int day;
    int pos;

    pos = date.find('-');
    year = std::atof(date.c_str());
    if ((pos < 0) || (pos > 4) || (!isStringDigit(date, pos)))
        return (0);
    date = date.substr(pos+1);
    pos = date.find('-');
    month = std::atof(date.c_str());
    if ((pos < 0) || (pos > 2) || (!isStringDigit(date, pos)) || (month > 12))
        return (0);
    date = date.substr(pos+1);
    day = std::atof(date.c_str());
    if ((pos < 0) || (pos > 2) || (!isStringDigit(date, pos)) || (day > 31)
        || ((month == 4) && (day > 30)) || ((month == 6) && (day > 30))
        || ((month == 9) && (day > 30)) || ((month == 11) && (day > 30))
        || ((year % 4 == 0) && (month == 2) && (day > 29)) || ((year % 4 == 1) && (month == 2) && (day > 28)))
        return (0);
    return (1);
}
