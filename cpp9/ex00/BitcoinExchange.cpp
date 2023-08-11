#include "BitcoinExchange.hpp"

// static bool isStringDigit(std::string str, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (!isdigit(str.c_str()[i]))
//             return (false);
//     }
//     return (true);
// }

BitcoinExchange::BitcoinExchange( void )
{
    std::ifstream dataStream;
    std::string str;
    int pos;
    double n;

    dataStream.open("data.csv");
    for(std::string line; std::getline(dataStream, line);)
    {
        pos = line.find(',');
        Date * date = new Date(line.substr(0, pos));
        if (date->isValid)
        {
            str = line.substr(pos+1);
            std::cout << str << std::endl;
            n = std::atof(str.c_str()); // Si hay problemas de precision tocar aqui
            this->data.insert(std::pair<Date *, double>(date, n));
        }
        else
            delete date;
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
    if(this != &asg)
    {
        //borrar elementos
        this->data.clear();
        this->data.insert(asg.data.begin(), asg.data.end()); //Está bien copiado asi??
    }
    return *this;
}

double BitcoinExchange::searchDate( Date date )
{
    for (std::map<Date *, double>::iterator it = this->data.begin(); it != this->data.end(); ++it)
    {
        if (!it->first->dateBefore(date))
        {

        }
    }
    return 0;
}
