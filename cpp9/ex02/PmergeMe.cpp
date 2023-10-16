/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:06:49 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 15:01:21 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ############################## */
/*          AUX FUNCTIONS         */
/* ############################## */

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

/* ############################## */
/*    CONSTUCTORS / DESTRUCTOR    */
/* ############################## */

PmergeMe::PmergeMe( void )
{}

PmergeMe::PmergeMe( char **argv, int argc, int opt )
{
    if (opt == 0)
    {
        for (int i = 1; i < argc; i++)
        {
            if (!*argv[i])
                continue ;
            if (!isDigitString(argv[i]))
                throw("Error");
            if (std::atol(argv[i]) > INT_MAX)
                throw("Error");
            this->_lst.push_back(std::atoi(argv[i]));
        }
        this->_lst = this->sort_lst(this->_lst);
    }
    else if (opt == 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (!*argv[i])
                continue ;
            if (!isDigitString(argv[i]))
                throw("Error");
            if (std::atol(argv[i]) > INT_MAX)
                throw("Error");
            this->_vct.push_back(atoi(argv[i]));
        }
        this->_vct = this->sort_vct(this->_vct);
    }
}

PmergeMe::PmergeMe( PmergeMe const &cpy )
{
    *this = cpy;
}

PmergeMe::~PmergeMe( void )
{}

/* ############################## */
/*             METHODS            */
/* ############################## */

PmergeMe & PmergeMe::operator=( PmergeMe const &asg )
{
    if (this != &asg)
    {
        std::list<int>      lst = asg.get_lst();
        std::vector<int>    vct = asg.get_vct();

        this->_lst.clear();
        this->_lst.insert(this->_lst.begin(), lst.begin(), lst.end());
        this->_vct.clear();
        this->_vct.insert(this->_vct.begin(), vct.begin(), vct.end());
    }
    return *this;
}

std::list<int> PmergeMe::get_lst() const
{
    return (this->_lst);
}

std::vector<int> PmergeMe::get_vct() const
{
    return (this->_vct);
}

std::list<int> PmergeMe::sort_lst( std::list<int> init )
{
    std::list<int> main, pend, ret;
    std::list<int>::iterator itr;
    int index = 0;

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
        ret = this->sort_lst(main);
    else
        ret = main;
    for (std::list<int>::iterator it = pend.begin(); it != pend.end(); it++)
    {
        itr = ret.begin();
        index = binarySearch_lst(ret, *it);
        std::advance(itr, index);
        ret.insert(itr, *it);
    }
    return (ret);
}

std::vector<int> PmergeMe::sort_vct( std::vector<int> init )
{
    std::vector<int> main, pend, ret;
    std::vector<int>::iterator itr;
    int index = 0;

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
        ret = this->sort_vct(main);
    else
        ret = main;
    for (std::vector<int>::iterator it = pend.begin(); it != pend.end(); it++)
    {
        itr = ret.begin();
        index = binarySearch_vct(ret, *it);
        std::advance(itr, index);
        ret.insert(itr, *it);
    }
    return (ret);
}

void PmergeMe::printList( void )
{
    for (std::list<int>::iterator it = this->_lst.begin(); it != this->_lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printVector( void )
{
    for (std::vector<int>::iterator it = this->_vct.begin(); it != this->_vct.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
