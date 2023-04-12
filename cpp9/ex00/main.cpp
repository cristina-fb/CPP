#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::map<std::string, float> btc;

    if (argc < 2)
        std::cout << "Error: could not open file." << std::endl;
    else if (argc > 2)
        std::cout << "Error: invalid number of arguments." << std::endl;
    else
    {
        BitcoinExchange a("HOLA");
        std::cout << a.day << std::endl;
        btc.insert(std::pair<std::string, float>("HOLA", 20.4));
        std::cout << argv[0] << btc["HOLA"] << std::endl;
    }
    return (0);
}
