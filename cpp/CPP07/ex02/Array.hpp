/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:37:55 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/29 11:17:38 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
    public:
        Array(): _array(NULL), _size(0){};
        ~Array(){
            delete _array;
        }
        Array(unsigned int size){
            _array = new T[size]();
            _size = size;
        }
        Array(Array const &array)
        {
            *this = array;
        }

        T &operator[](unsigned int index) const
        {
            if (index >= _size)
                throw MemoryAccessError();
            return (_array[index]);
        }
        Array<T> &operator=(Array const &array)
        {
            unsigned int i;
            unsigned int max;

            max = array.getSize();
            _array = new T[max]();
            i = 0;
            while (i < max)
            {
                _array[i] = array[i];
                i++;
            }
            _size = max;
            return (*this);
        }
        unsigned int getSize() const
        {
            return (_size);
        }
        class MemoryAccessError: public std::exception
        {
            virtual const char *what() const throw(){
                return ("Memory access error");
            }
        };
    private:
        T *_array;
        unsigned int _size;
};

template< typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &array)
{
    unsigned int i;
    unsigned int max;

    i = 0;
    max = array.getSize();
    while (i < max)
    {
        out << array[i];
        i++;
    }
}

#endif