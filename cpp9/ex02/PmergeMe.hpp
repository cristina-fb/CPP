#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP
class PmergeMe
{
    public:
        PmergeMe( void );
        PmergeMe( PmergeMe & cpy );
        ~PmergeMe( void );

        PmergeMe & operator=( PmergeMe & asg );
};
#endif
