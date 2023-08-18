#include "PmergeMe.hpp"

static bool isDigitString( std::string str )
{
    for (unsigned long i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

static int binarySearch( std::list<int> lst, int value )
{
    int min = 0, max = lst.size() - 1, avg;

    while (min != max)
    {
        avg = (min + max) / 2;
        //std::cout << "      avg: " << avg << " min: " << min << " max: " << max << std::endl;
        if (*std::next(lst.begin(), avg) > value)
            max = avg;
        else
            min = avg + 1;
    }
    //std::cout << "      Res: " << min << std::endl;
    return (min);
}

PmergeMe::PmergeMe( void )
{}

PmergeMe::PmergeMe( char **argv, int argc )
{
    // Check argument list and convert into integers
    for (int i = 1; i < argc; i++)
    {
        if (!isDigitString(argv[i]))
        {
            std::cout << "Error" << std::endl;
            std::exit(0);
        }
        lst.push_back(atoi(argv[i]));
        // vct.pushback(atoi(argv[i]));
    }

    // Check for dupes
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        if (std::count(lst.begin(), lst.end(), *it) > 1)
        {
            std::cout << "Error" << std::endl;
            std::exit(0);
        }
    }
}

PmergeMe::PmergeMe( PmergeMe & cpy )
{
    *this = cpy;
}

PmergeMe::~PmergeMe( void )
{}

PmergeMe & PmergeMe::operator=( PmergeMe & asg )
{
    if (this != &asg)
    {
        this->lst.clear();
        this->lst.insert(this->lst.begin(), asg.lst.begin(), asg.lst.end());
    }
    return *this;
}

std::list<int> PmergeMe::mergeInsertionSort( std::list<int> init )
{
    // Create main and pend lists sorted by pairs
    std::list<int> main, pend;
    for (std::list<int>::iterator it = init.begin(); it != init.end(); it++)
    {
        if (std::next(it, 1) == init.end())
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
        main = this->mergeInsertionSort(main);
        // move pend values looking at sorted lst
    }

    // calc jacobsthal order
    for (std::list<int>::iterator it = pend.begin(); it != pend.end(); it++)
    {
        //std::cout << "VALOR: " << *it << std::endl;
        int index = binarySearch(main, *it);
        main.insert(std::next(main.begin(), index), *it);
        // printList(main);
        // std::cout << std::endl;
    }
    return (main);
}
