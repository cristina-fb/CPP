#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return (0);
    }
    try
    {
        RPN a(argv[1]);
        std::cout << a.getRes() << std::endl;
    }
    catch(char const * exc)
    {
        std::cout << exc << std::endl;
    }
    return (0);
}
