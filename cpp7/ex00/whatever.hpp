/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:24:06 by crisfern          #+#    #+#             */
/*   Updated: 2022/12/20 16:32:28 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void swap(T & a, T & b)
{
	T aux = a;
	a = b;
	b = aux;
}

template<typename T>
T & min(T & a, T & b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
T & max(T & a, T & b)
{
	if (a > b)
		return a;
	return b;
}
