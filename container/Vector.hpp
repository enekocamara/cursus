/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:26:11 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/10 13:02:55 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP 
#define VECTOR_HPP


template < class T, class Alloc = allocator<T> >
class Vector
{
    public:
        explicit Vector (const Alloc& alloc = Alloc());
        explicit Vector (size_t n, const T& val = T(), const Alloc& alloc = Alloc());
        template <class InputIterator> vector (InputIterator first, InputIterator last, const Alloc& alloc = Alloc());
        vector (const vector& x);
}

#endif