/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:15 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/11 11:59:03 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T * arr, unsigned int num, void fun(T const &))
{
	if (arr && fun)
	{
		for(unsigned int i = 0; i < num; i++)
		{
			fun(arr[i]);
		}
	}
}
#endif
