#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

void printList( std::list<int> lst )
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printVector( std::vector<int> vct )
{
    for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::list<int>  lst;
    std::vector<int>  vct;
    std::clock_t init_lst, init_vct, end_lst, end_vct;
    PmergeMe        a(argv, argc);

    if (argc < 2)
        return (0);
    init_lst = std::clock();
    lst = a.sort_lst(a.lst);
    end_lst = std::clock();
    init_vct = std::clock();
    vct = a.sort_vct(a.vct);
    end_vct = std::clock();
    printList(lst);
    std::cout << "Time elapsed lst: " << end_lst - init_lst << std::endl;
    printVector(vct);
    std::cout << "Time elapsed vct: " << end_vct - init_vct << std::endl;
    return (0);
}
