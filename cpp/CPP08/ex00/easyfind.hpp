/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:48:23 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/09 11:48:58 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T> int easyfind(T container, int n)
{
    if (std::find(container.begin(), container.end(), n) != container.end())
        return (1);
    return (0);
}

#endif