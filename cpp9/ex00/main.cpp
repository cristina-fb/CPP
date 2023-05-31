#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"
#define E1 "Error: bad input"
#define E2 "Error: not a positive number"
#define E3 "Error: too large a number"
#define E4 "Error: not a number"

int main(int argc, char **argv)
{
    std::map<std::string, float> btc;
    BitcoinExchange data("data.csv", ',', 0);
    (void)argv;
    if (argc < 2)
        std::cout << "Error: could not open file." << std::endl;
    else if (argc > 2)
        std::cout << "Error: invalid number of arguments." << std::endl;
    else
    {
        BitcoinExchange a(argv[1], '|', 1);
        for (std::multimap<std::string, double>::iterator it = a.Data.begin(); it != a.Data.end(); ++it)
        {
            if ((*it).second == -1)
                std::cout << E1 << " => " << (*it).first << std::endl;
            else if ((*it).second == -2)
                std::cout << E2 << std::endl;
            else if ((*it).second == -3)
                std::cout << E3 << std::endl;
            else if ((*it).second == -4)
                std::cout << E4 << std::endl;
            else
                std::cout << (*it).first << " => " << (*it).second << " = " << std::endl;
        }
    }
    return (0);
}
