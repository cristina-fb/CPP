#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP
# include <iostream>
# include <algorithm>
# include <list>

class PmergeMe
{
    public:
        PmergeMe( void );
        PmergeMe( char **argv, int argc );
        PmergeMe( PmergeMe & cpy );
        ~PmergeMe( void );

        PmergeMe & operator=( PmergeMe & asg );
        std::list<int> mergeInsertionSort( std::list<int> init );

        std::list<int> lst;
};
#endif
