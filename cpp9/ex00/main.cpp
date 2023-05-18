#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::map<std::string, float> btc;
    (void)argv;
    if (argc < 2)
        std::cout << "Error: could not open file." << std::endl;
    else if (argc > 2)
        std::cout << "Error: invalid number of arguments." << std::endl;
    else
    {
        BitcoinExchange a("data.csv", "input.txt");
    }
    return (0);
}
