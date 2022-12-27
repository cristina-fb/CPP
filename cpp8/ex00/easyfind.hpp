/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:15:52 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/27 16:47:58 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <list>

template<typename T>
T easyfind(std::list<T> lst , int n)
{
	try
	{
		return *(std::find(lst.begin(), lst.end(), n));
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
#endif
