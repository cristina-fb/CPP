#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"
#include "Date.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc < 2)
        std::cout << "Error: could not open file." << std::endl;
    else if (argc > 2)
        std::cout << "Error: invalid number of arguments." << std::endl;
    else
    {
        BitcoinExchange data;
        data.printInputResult(argv[1]);
    }
    return (0); 
}
