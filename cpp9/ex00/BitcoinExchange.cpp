#include "BitcoinExchange.hpp"

static bool isStringDigitFloat(std::string str, int n)
{
    int pointFlag = 0;

    for (int i = 0; i < n; i++)
    {
        if (!isdigit(str.c_str()[i]) && (str.c_str()[i] != '.'))
            return (false);
        if (str.c_str()[i] == '.')
            pointFlag++;
    }
    if (pointFlag > 1)
        return false;
    return (true);
}

BitcoinExchange::BitcoinExchange( void )
{
    std::ifstream dataStream;
    std::string str;
    std::string dstr;
    int pos;
    double n;

    dataStream.open("data.csv");
    for(std::string line; std::getline(dataStream, line);)
    {
        pos = line.find(',');
        dstr = line.substr(0, pos);
        dstr = line.substr(dstr.find_first_not_of(" \f\n\r\t\v"), dstr.find_last_not_of(" \f\n\r\t\v") + 1);
        Date * date = new Date(dstr);
        if (date->isValid)
        {
            str = line.substr(pos+1);
            str = str.substr(str.find_first_not_of(" \f\n\r\t\v"), str.find_last_not_of(" \f\n\r\t\v") + 1);
            n = std::atof(str.c_str());
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
    for (std::map<Date *, double>::iterator it = this->data.begin(); it != this->data.end(); ++it)
        delete it->first;
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

double BitcoinExchange::searchDateValue( Date date )
{
    std::map<Date *, double>::iterator it;

    for (it = this->data.begin(); it != this->data.end(); ++it)
    {
        if (it->first->dateBefore(date))
        {
            if (it == this->data.begin())
                return 0;
            return (--it)->second;
        }
    }
    return (--it)->second;
}

void BitcoinExchange::printInputResult( std::string filename )
{
    std::ifstream dataStream;
    std::string str;
    std::string dstr;
    int pos;
    double n;

    dataStream.open(filename);
    for(std::string line; std::getline(dataStream, line);)
    {
        pos = line.find('|');
        dstr = line.substr(0, pos);
        dstr = dstr.substr(dstr.find_first_not_of(" \f\n\r\t\v"), dstr.find_last_not_of(" \f\n\r\t\v") + 1);
        Date fdate(dstr);
        if (fdate.isValid)
        {
            str = line.substr(pos+1);
            str = str.substr(str.find_first_not_of(" \f\n\r\t\v"), str.find_last_not_of(" \f\n\r\t\v") + 1);
            n = std::atof(str.c_str());
            if (!isStringDigitFloat(str.c_str(), str.length()) || (n < 0))
                std::cout << E2 << std::endl;
            else if (n > 1000)
                std::cout << E3 << std::endl;
            else
                std::cout << dstr << " => " << n << " = " << n * this->searchDateValue(fdate) << std::endl;
        }
        else
            std::cout << E1 << " => " << dstr << std::endl;
    }
    dataStream.close();

}
