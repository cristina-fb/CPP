#include "PmergeMe.hpp"

bool isDigitString( std::string str )
{
    for (unsigned long i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

std::list<int> jacobsthal(int max)
{
    std::list<int> lst;
    int n = 0, value = 0, i = 0;

    while (1)
    {
        value *= 2;
        if ((n % 2) && n)
            value--;
        else
            value++;
        if ((value >= max) && (!value || (value == 1)))
            break;
        if (value >= max)
            value = max;
        if (value > 1)
        {
            if (!lst.empty())
                i = *lst.begin();
            else
                i = 1;
            lst.push_back(value);
            for (int loop = value - 1; loop > i; loop--)
                lst.push_back(loop);
            if (value >= max)
                break;
        }
        n++;
    }
    return (lst);
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
    std::list<int> main, pend, ret, order;
    std::list<int>::iterator itm, itp, id1, id2, id3;

    for (std::list<int>::iterator it = init.begin(); it != init.end(); it++)
    {
        if (++it == init.end())
        {
            pend.push_back(*(--it));
        }
        else if (*(--it) < *(++it))
        {
            pend.push_back(*(--it));
            main.push_back(*(++it));
        }
        else
        {
            main.push_back(*(--it));
            pend.push_back(*(++it));
        }
    }
    if (main.size() > 1)
    {
        ret = this->mergeInsertionSort(main);
        //sort pend values
        itm = main.begin();
        for (std::list<int>::iterator it = ret.begin(); it != ret.end(); it++)
        {
            if (*it != *itm)
            {
                id1 = pend.begin();
                id2 = pend.begin();
                id3 = std::find(main.begin(), main.end(), *it);
                std::advance(id1, std::distance(main.begin(), itm));
                std::advance(id2, std::distance(main.begin(), id3));
                std::iter_swap(id1, id2);
                std::iter_swap(itm, id3);
            }
            itm++;
        }
    }
    else
        ret = main;
    // TODO calc jacobsthal order
    // insert first pend element
    order = jacobsthal(pend.size());
    std::cout << "----------------------------------" << std::endl;
    std::cout << "SIZE: " << pend.size() << std::endl;
    for (std::list<int>::iterator it = pend.begin(); it != pend.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    for (std::list<int>::iterator it = order.begin(); it != order.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    ret.push_front(*pend.begin());
    pend.erase(pend.begin());
    for (std::list<int>::iterator it = order.begin(); it != order.end(); it++)
    {
        itp = pend.begin();
        std::advance(itp, (*it) - 1);
        int index = binarySearch(ret, *itp);
        ret.insert(std::next(ret.begin(), index), *itp); //arreglar
    }
    for (std::list<int>::iterator it = ret.begin(); it != ret.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    return (ret);
}
