#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error I" << std::endl;
        return (0);
    }
    try
    {
        if (*argv[1])
        {
            RPN a(argv[1]);
            std::cout << a.getRes() << std::endl;
        }
        else
            throw("Error J");
    }
    catch(char const * exc)
    {
        std::cout << exc << std::endl;
    }
}
