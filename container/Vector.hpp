/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:26:11 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/11 13:05:40 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP 
#define VECTOR_HPP

#include <memory>
/*
template <class T> class allocator;

template <class T> class Alloc;
*/
template < class T, class Alloc = std::allocator<T> >
class Vector
{
    public:
        explicit Vector (const Alloc &alloc = Alloc());
        explicit Vector (size_t n, const T& val = T(), const Alloc& alloc = Alloc());
        template <class InputIterator> Vector (InputIterator first, InputIterator last, const Alloc& alloc = Alloc());
        Vector (const Vector& x);

        size_t capacity() const;
        size_t size() const;
        T *begin();
        T *end();
    private:
        T *_array;
        Alloc _alloc;
        size_t _size;
        size_t _capacity;                
};


template <class T, class Alloc>
Vector<T, Alloc>::Vector (const Alloc &alloc)
{
    _alloc = alloc;
    _size = 0;
    _capacity = 0;
    _array = NULL;
}

template <class T, class Alloc>
Vector<T, Alloc>::Vector (size_t n, const T& val, const Alloc& alloc)
{
    _size = n;
    _alloc = alloc;
    _array = _alloc.allocate(n);
    _capacity = n;
    for(size_t i = 0; i < n; i++)
        _alloc.construct(&_array[i], val);
        
}

template <class T, class Alloc>
template <class InputIterator>
Vector<T, Alloc>::Vector(InputIterator first, InputIterator last, const Alloc& alloc)
{
    _size = std::distance(first, last);
    _array = alloc.allocatite(_size);
    _capacity = _size;
    for(size_t i = 0; i < _size; i++)
        _alloc.construct(&_array[i], *(first + i));
}

template <class T, class Alloc>
size_t Vector<T, Alloc>::capacity() const
{
    return (_capacity);
}

template <class T, class Alloc>
size_t Vector<T, Alloc>::size() const
{
    return (_size);
}


#endif