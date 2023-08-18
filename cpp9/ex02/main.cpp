#include "PmergeMe.hpp"
#include <iostream>

void printList( std::list<int> lst )
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::list<int>  lst;
    PmergeMe        a(argv, argc);

    if (argc < 2)
        return (0);
    
    lst = a.mergeInsertionSort(a.lst);
    printList(lst);
    return (0);
}
