/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:15 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/20 17:12:25 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename X, typename Y, typename Z>
void iter(X * arr, Y num, Z * fun)
{
	for(int i = 0; i < num; i++)
	{
		arr[i] = fun(arr[i]);
	}
}
