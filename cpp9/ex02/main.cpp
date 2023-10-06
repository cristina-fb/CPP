#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    std::list<int>  lst;
    std::vector<int>  vct;
    std::clock_t init_lst, init_vct, end_lst, end_vct;

    if (argc < 2)
        return (0);
    try
    {
        init_lst = std::clock();
        PmergeMe    a(argv, argc, 0);
        end_lst = std::clock();

        init_vct = std::clock();
        PmergeMe    b(argv, argc, 1);
        end_vct = std::clock();

        // PRINT VALUES
        std::cout << "Before        : ";
        for (int i = 1; i < argc; i++)
            if (*argv[i])
                std::cout << argv[i] << " ";
        std::cout << std::endl;

        std::cout << "After   (list): ";
        a.printList();
        std::cout << "After (vector): ";
        b.printVector();
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << end_lst - init_lst  << " ms" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << end_vct - init_vct << " ms" << std::endl;
    }
    catch(char const * exc)
    {
        std::cerr << exc << '\n';
    }
    return (0);
}
