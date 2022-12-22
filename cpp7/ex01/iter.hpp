/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:15 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/22 12:25:18 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename X, typename Y, typename Z>
void iter(X * arr, Y num, Z * fun)
{
	for(int i = 0; i < num; i++)
	{
		arr[i] = fun(arr[i]);
	}
}
#endif
