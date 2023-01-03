/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:31:42 by crisfern          #+#    #+#             */
/*   Updated: 2023/01/03 14:53:19 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP
# include "Data.hpp"
uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);
#endif
