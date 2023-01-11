/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:15:52 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 19:50:55 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <exception>
# include <algorithm>
# include <list>

template<typename T>
void easyfind(std::list<T> lst, int n)
{
	if (std::find(lst.begin(), lst.end(), n) == lst.end())
	{
		throw("Element wasn't found!! :(");
	}
	std::cout << "Element was found!! :)" << std::endl;
}
#endif
