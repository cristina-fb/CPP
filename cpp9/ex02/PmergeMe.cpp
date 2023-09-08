#include "PmergeMe.hpp"

static bool isDigitString( std::string str )
{
    for (unsigned long i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

static bool isSorted_vct( std::vector<int> vct )
{
    int a;

    for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
    {
        a = *it;
        it++;
        if (it == vct.end())
            break ;
        if (a > *it)
            return (false);
        it--;
    }
    return (true);
}

static bool isSorted_lst( std::list<int> lst )
{
    int a;

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        a = *it;
        it++;
        if (it == lst.end())
            break ;
        if (a > *it)
            return (false);
        it--;
    }
    return (true);
}

static std::vector<int> jacobsthal_vct( int max )
{
    std::vector<int> vct;
    int n = 0, value = 0, last = 1;

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
            for (int loop = value; loop > last; loop--)
                vct.push_back(loop);
            if (value >= max)
                break;
        }
        last = value;
        n++;
    }
    return (vct);
}

static std::list<int> jacobsthal_lst( int max )
{
    std::list<int> lst;
    int n = 0, value = 0, last = 1;

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
            for (int loop = value; loop > last; loop--)
                lst.push_back(loop);
            if (value >= max)
                break;
        }
        last = value;
        n++;
    }
    return (lst);
}

static int binarySearch_vct( std::vector<int> vct, int value )
{
    int min = 0, max = vct.size(), avg;
    std::vector<int>::iterator it;

    while (min != max)
    {
        avg = (min + max) / 2;
        it = vct.begin();
        std::advance(it, avg);
        if (*it > value)
            max = avg;
        else
            min = avg + 1;
    }
    return (min);
}

static int binarySearch_lst( std::list<int> lst, int value )
{
    int min = 0, max = lst.size(), avg;
    std::list<int>::iterator it;

    while (min != max)
    {
        avg = (min + max) / 2;
        it = lst.begin();
        std::advance(it, avg);
        if (*it > value)
            max = avg;
        else
            min = avg + 1;
    }
    return (min);
}

PmergeMe::PmergeMe( void )
{}

PmergeMe::PmergeMe( char **argv, int argc )
{
    for (int i = 1; i < argc; i++)
    {
        if (!isDigitString(argv[i]))
        {
            std::cout << "Error" << std::endl;
            std::exit(0);
        }
        lst.push_back(atoi(argv[i]));
        vct.push_back(atoi(argv[i]));
    }

    // TODO : Hacer comprobación para vector ??
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
        this->vct.clear();
        this->vct.insert(this->vct.begin(), asg.vct.begin(), asg.vct.end());
    }
    return *this;
}

std::list<int> PmergeMe::sort_lst( std::list<int> init )
{
    std::list<int> main, pend, ret, order;
    std::list<int>::iterator itm, itp, itr, id1, id2, id3;

    if (isSorted_lst(init))
        return (init);
    for (std::list<int>::iterator it = init.begin(); it != init.end(); it++)
    {
        if (++it == init.end())
            pend.push_back(*(--it));
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
        ret = this->sort_lst(main);
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
    order = jacobsthal_lst(pend.size());
    ret.push_front(*pend.begin());
    for (std::list<int>::iterator it = order.begin(); it != order.end(); it++)
    {
        itp = pend.begin();
        itr = ret.begin();
        std::advance(itp, (*it) - 1);
        int index = binarySearch_lst(ret, *itp);
        std::advance(itr, index);
        ret.insert(itr, *itp);
    }
    return (ret);
}

std::vector<int> PmergeMe::sort_vct( std::vector<int> init )
{
    std::vector<int> main, pend, ret, order;
    std::vector<int>::iterator itm, itp, itr, id1, id2, id3;

    if (isSorted_vct(init))
        return (init);
    for (std::vector<int>::iterator it = init.begin(); it != init.end(); it++)
    {
        if (++it == init.end())
            pend.push_back(*(--it));
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
        ret = this->sort_vct(main);
        itm = main.begin();
        for (std::vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
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
    order = jacobsthal_vct(pend.size());
    ret.insert(ret.begin(), *pend.begin());
    for (std::vector<int>::iterator it = order.begin(); it != order.end(); it++)
    {
        itp = pend.begin();
        itr = ret.begin();
        std::advance(itp, (*it) - 1);
        int index = binarySearch_vct(ret, *itp);
        std::advance(itr, index);
        ret.insert(itr, *itp);
    }
    return (ret);
}
