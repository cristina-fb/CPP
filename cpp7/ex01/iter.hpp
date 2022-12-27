/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:15 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/27 13:31:36 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T * arr, unsigned int num, T (*fun)(T))
{
	if (arr && fun)
	{
		for(unsigned int i = 0; i < num; i++)
		{
			arr[i] = fun(arr[i]);
		}
	}
}
#endif
