/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:05:47 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 17:18:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::string spaceTrim( std::string str )
{
    std::string::size_type init = str.find_first_not_of(" \f\n\r\t\v");
    if (init != std::string::npos)
        str = str.substr(init);
    std::string::size_type end = str.find_last_not_of(" \f\n\r\t\v");
    if (end != std::string::npos)
        str = str.substr(0, end + 1);
    return str;
}

static bool isSpacesString( std::string str )
{
    for (unsigned long i = 0; i < str.length(); i++)
    {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}

static bool isStringDigitFloat( std::string str, int n )
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
    if (!dataStream)
        throw("Error: could not open file.");
    for(std::string line; std::getline(dataStream, line);)
    {
        if (isSpacesString(line) || line.empty())
            continue ;
        pos = line.find(',');
        if (pos == -1)
            continue ;
        dstr = spaceTrim(line.substr(0, pos));
        if (isSpacesString(dstr) || dstr.empty())
            continue ;
        Date * date = new Date(dstr);
        str = spaceTrim(line.substr(pos+1));
        if (str.empty() || isSpacesString(str) || !isStringDigitFloat(str, str.length()) || !date->isValid)
        {
            delete date;
            continue;
        }
        n = std::atof(str.c_str());
        this->data.insert(std::pair<Date *, double>(date, n));
    }
    dataStream.close();
}

BitcoinExchange::BitcoinExchange( std::string dbfilename )
{
    std::ifstream dataStream;
    std::string str;
    std::string dstr;
    int pos;
    double n;

    dataStream.open(dbfilename);
    if (!dataStream)
        throw("Error: could not open file.");
    for(std::string line; std::getline(dataStream, line);)
    {
        if (isSpacesString(line) || line.empty())
            continue ;
        pos = line.find(',');
        if (pos == -1)
            continue ;
        dstr = spaceTrim(line.substr(0, pos));
        if (isSpacesString(dstr) || dstr.empty())
            continue ;
        Date * date = new Date(dstr);
        str = spaceTrim(line.substr(pos+1));
        if (str.empty() || isSpacesString(str) || !isStringDigitFloat(str, str.length()) || !date->isValid)
        {
            delete date;
            continue;
        }
        n = std::atof(str.c_str());
        this->data.insert(std::pair<Date *, double>(date, n));
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
        for (std::map<Date *, double>::iterator it = this->data.begin(); it != this->data.end(); ++it)
            delete it->first;
        this->data.clear();
        for (std::map<Date *, double>::iterator it = asg.data.begin(); it != asg.data.end(); ++it)
            this->data.insert(std::pair<Date *, double>(new Date(*it->first), it->second));
    }
    return *this;
}

double BitcoinExchange::searchDateValue( Date date )
{
    std::map<Date *, double>::iterator it;

    if (this->data.size() > 0)
    {
        for (it = this->data.begin(); it != this->data.end(); ++it)
        {
            if (it->first->dstr > date.dstr)
            {
                if (it == this->data.begin())
                    return 0;
                return (--it)->second;
            }
        }
        return (--it)->second;
    }
    return 0;
}

void BitcoinExchange::printInputResult( std::string filename )
{
    std::ifstream dataStream;
    std::string str;
    std::string dstr;
    int first = 0;
    int pos;
    double n;

    dataStream.open(filename);
    if (!dataStream)
        std::cout << "Error: could not open file." << std::endl;
    for(std::string line; std::getline(dataStream, line);)
    {
        if (line.empty() || isSpacesString(line))
            continue ;
        pos = line.find('|');
        if (pos == -1)
            std::cout << E1 << " => " << line << std::endl;
        else
        {
            dstr = spaceTrim(line.substr(0, pos));
            if (isSpacesString(dstr) || dstr.empty())
                std::cout << E1 << " => " << line << std::endl;
            else
            {
                Date fdate(dstr);
                if (fdate.isValid)
                {
                    str = spaceTrim(line.substr(pos+1));
                    n = std::atof(str.c_str());
                    if (!isStringDigitFloat(str.c_str(), str.length()) || (n < 0) || str.empty() || isSpacesString(str))
                        std::cout << E2 << std::endl;
                    else if (n > 1000)
                        std::cout << E3 << std::endl;
                    else
                        std::cout << dstr << " => " << n << " = " << n * this->searchDateValue(fdate) << std::endl;
                }
                else if (first)
                    std::cout << E1 << " => " << dstr << std::endl;
            }
        }
        first++;
    }
    dataStream.close();
}
