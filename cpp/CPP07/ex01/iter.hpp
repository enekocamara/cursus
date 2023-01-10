/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:21:10 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/29 10:34:09 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> void sum(T &a)
{
    a++;
}

template <typename T> void show(T &a)
{
    std::cout << "[" << a << "]";
}

template <typename T> void iter(T *add, size_t length, void(*f)(T&))
{
    size_t i;

    i = 0;
    while (i < length)
    {
        f(add[i]);
        i++;
    }
}