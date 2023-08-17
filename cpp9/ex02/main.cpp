#include "PmergeMe.hpp"
#include <iostream>
#include <list>

static bool isDigitString( std::string str )
{
    for (unsigned long i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

void printList( std::list<int> lst )
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::list<int> lst, main, pend;

    // Arguments check!
    if (argc < 2)
        return (0);

    // Check argument list and convert into ints
    for (int i = 1; i < argc; i++)
    {
        if (!isDigitString(argv[i]))
        {
            std::cout << "Error" << std::endl;
            return (0);
        }
        lst.push_back(atoi(argv[i]));
    }
    // Need to check here for dupes

    // HERE STARTS RECURSION !!!
    // Create main and pend lists sorted by pairs
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        if (std::next(it, 1) == lst.end())
            pend.push_back(*it);
        else if (*it < *(std::next(it, 1)))
        {
            pend.push_back(*it);
            it++;
            main.push_back(*it);
        }
        else
        {
            main.push_back(*it);
            it++;
            pend.push_back(*it);
        }
    }
    if (main.size() != 1)
    {
        // sorted = sort(main);
        // move pend values looking at sorted lst
    }
    // calc jacobsthal order
    // insert pend values to main
    // return main


    // Print lists
    printList(main);
    printList(pend);
    return (0);
}
