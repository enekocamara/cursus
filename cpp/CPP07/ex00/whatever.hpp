/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:12:39 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/29 10:15:36 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> T min(T a, T b)
{
    if (a < b)
        return (a); 
    return (b);
}

template <typename T> T max(T a, T b)
{
    if (a > b)
        return (a); 
    return (b);
}

template <typename T> void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}