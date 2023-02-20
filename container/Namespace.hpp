/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Namespace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:04:09 by ecamara           #+#    #+#             */
/*   Updated: 2023/02/15 11:41:09 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Vector.hpp"
#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <memory>
#include <iterator>
#include <iostream>
namespace ft
{
    /*------------------------------------------ MACROS ------------------------------------------*/

    template <bool Cond, class T = void> struct enable_if
    {
        
    };
    
    template<class T> struct enable_if<true, T>
    {
        typedef T type;
    };

    template<class It>
    typename std::iterator_traits<It>::difference_type 
        do_distance(It first, It last, std::input_iterator_tag)
    {
        typename std::iterator_traits<It>::difference_type result = 0;
    
        while (first != last)
        {
            first++;
            result++;
        }
        return (result);
    }

    template<class Iter>
    struct iterator_trits
    {
        typedef typename Iter::difference_type      difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;  
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;
    };
}

#endif