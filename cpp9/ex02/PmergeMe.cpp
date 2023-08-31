#include "PmergeMe.hpp"

bool isDigitString( std::string str )
{
    for (unsigned long i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

int binarySearch( std::list<int> lst, int value )
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

std::list<std::pair<int, int> >::iterator find_pair(std::list<std::pair<int, int> > lst, int value)
{
    std::list<std::pair<int, int> >::iterator it = lst.begin();

    for (it = lst.begin(); it != lst.end(); it++)
        if (it->first == value)
            break ;
    return it;
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
    std::list<std::pair<int, int> >::iterator itm;
    std::list<std::pair<int,int> > main;
    std::list<int> ret, arg;
    int aux;

    for (std::list<int>::iterator it = init.begin(); it != init.end(); it++)
    {
        if (std::next(it, 1) == init.end())
        {
            main.push_back(std::make_pair(-1,*it));
        }
        else if (*it < *(std::next(it, 1)))
        {
            aux = *it;
            it++;
            main.push_back(std::make_pair(*it, aux));
        }
        else
        {
            aux = *it;
            it++;
            main.push_back(std::make_pair(aux, *it));
        }
    }
    std::cout << "---------- ITERACION ------------" << std::endl;
    for (std::list<std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
        std::cout << it->first << " ";
    std::cout << std::endl;
    for (std::list<std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
        std::cout << it->second << " ";
    std::cout << std::endl;
    if ((main.size() > 2 ) || ((main.size() == 2) && (std::next(main.end(), -1)->first != -1)))
    {
        for (std::list<std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
            if (it->first != -1)
                arg.push_back(it->first);
        ret = this->mergeInsertionSort(arg);
        //sort pend values
        itm = main.begin();
        for (std::list<int>::iterator it = ret.begin(); it != ret.end(); it++)
        {
            if (*it != itm->first)
            {
                iter_swap(itm, find_pair(main, *it)); //Esta función es una mierda
            }
            itm++;
        }
    }
    else
        ret.push_back(main.begin()->first);
    std::cout << std::endl;
    for (std::list<std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
        std::cout << it->first << " ";
    std::cout << std::endl;
    for (std::list<std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
        std::cout << it->second << " ";
    std::cout << std::endl;

    // calc jacobsthal order
    ret.push_front(main.begin()->second);
    main.erase(main.begin());
    for (std::list<std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
    {
        int index = binarySearch(ret, it->second);
        ret.insert(std::next(ret.begin(), index), it->second);
    }
    std::cout << "RET" << std::endl;
    for (std::list<int>::iterator it = ret.begin(); it != ret.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    return (ret);
}
