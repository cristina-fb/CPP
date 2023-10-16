/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:07:22 by crisfern          #+#    #+#             */
/*   Updated: 2023/10/16 12:08:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP
# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <limits>

class PmergeMe
{
    public:
        PmergeMe( char **argv, int argc, int opt );
        PmergeMe( PmergeMe const &cpy );
        ~PmergeMe( void );

        PmergeMe & operator=( PmergeMe const &asg );
        std::list<int> get_lst() const;
        std::vector<int> get_vct() const;

        std::list<int> sort_lst( std::list<int> init );
        std::vector<int> sort_vct( std::vector<int> init );
        void printList( void );
        void printVector( void );
    
    private:
        PmergeMe( void );
        
        std::list<int> _lst;
        std::vector<int> _vct;
};
#endif
