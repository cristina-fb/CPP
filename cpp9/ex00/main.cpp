#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"
#include "Date.hpp"

void leaks(void)
{
    system("leaks -q btc");
}

int main(int argc, char **argv)
{
    atexit(leaks);
    if (argc < 2)
        std::cout << "Error: could not open file." << std::endl;
    else if (argc > 2)
        std::cout << "Error: invalid number of arguments." << std::endl;
    else
    {
        BitcoinExchange *data = new BitcoinExchange();
        BitcoinExchange a(*data);
        delete data;
        a.printInputResult(argv[1]);
    }
    return (0); 
}
