#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP
# include <iostream>
# include <algorithm>
# include <list>
# include <vector>

class PmergeMe
{
    public:
        PmergeMe( void );
        PmergeMe( char **argv, int argc );
        PmergeMe( PmergeMe & cpy );
        ~PmergeMe( void );

        PmergeMe & operator=( PmergeMe & asg );
        std::list<int> sort_lst( std::list<int> init );
        std::vector<int> sort_vct( std::vector<int> init );

        std::list<int> lst;
        std::vector<int> vct;
};
#endif
