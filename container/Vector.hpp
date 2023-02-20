/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:26:11 by ecamara           #+#    #+#             */
/*   Updated: 2023/02/15 13:27:48 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP 
#define VECTOR_HPP

#include <memory>


namespace ft{
 /*---------------------------------- VECTOR ----------------------------------*/

    template < class T, class Alloc = std::allocator<T> >
    class Vector
    {
        public:
            typedef T                                                               value_type;
            typedef Alloc                                                           allocator_type;
            typedef typename allocator_type::reference                              reference;
            typedef typename allocator_type::const_reference                        const_reference;
            typedef typename allocator_type::pointer                                pointer;
            typedef typename allocator_type::const_pointer                          const_pointer;
            typedef pointer                                                         iterator;
            typedef const_pointer                                                   const_iterator;
            typedef std::reverse_iterator<iterator>                                 reverse_iterator;
            typedef std::reverse_iterator<const_iterator>                           const_reverse_iterator;
            typedef typename std::iterator_traits<iterator>::difference_type        difference_type;
            typedef difference_type                                                 size_type;

            /*-------- CONSTRUCT --------*/
        
            explicit Vector (const Alloc &alloc = Alloc())
            {
                _alloc = alloc;
                _size = 0;
                _capacity = 0;
                _array = NULL;
            }
            explicit Vector (size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc())
            {
                _size = n;
                _alloc = alloc;
                _array = _alloc.allocate(n);
                _capacity = n;
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(&_array[i], val);
            }
            explicit Vector (const Vector& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity), _array(_alloc.allocate(_capacity)){
                for (size_type i = 0; i < _size; i++) {
                    _alloc.construct(&_array[i], x._array[i]);
                }
            }

            template <class InputIterator>
            explicit Vector (InputIterator first, InputIterator last, const Alloc& alloc = Alloc(), typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
            {
                _size = std::distance(first, last);
                _alloc = alloc;
                _array = _alloc.allocate(_size);
                _capacity = _size;
                for(size_type i = 0; i < _size; i++)
                    _alloc.construct(&_array[i], *(first + i));
            }
            
            /*----------- OPERATOR OVERLOAD -----------*/

            ft::Vector<value_type>& operator=(const Vector& x){
                if (this != &x){
                    if (_capacity < x._size){
                        clear();
                        reserve(x._size);
                    }
                    for (size_type i = 0; i < x._size; i++) {
                        _array[i] = x._array[i];
                    }
                    _size = x._size;
                }
                return *this;
            }
            
            void clear(){
                for (size_type i = 0 ; i < _size; i++){
                    _alloc.destroy(&_array[i]);
                }
                _size = 0;
            }

            void reserve(size_type n){
                if (n <= _capacity)
                    return;
            
                pointer new_array = _alloc.allocate(n);
                for (size_type i = 0; i < _size; i++) {
                    _alloc.construct(&new_array[i], _array[i]);
                    _alloc.destroy(&_array[i]);
                }
                _alloc.deallocate(_array, _capacity);
                _array = new_array;
                _capacity = n;
            }
            
            void    push_back(value_type val){
                if (_capacity < _size + 1){
                    reserve(_size + 1);
                }
                _size++;
                _alloc.construct(&_array[_size], val);
            }

            
            
            size_type  capacity() const {return _capacity;}
            size_type  size() const{return _size;}
            pointer begin()
            {
                return (&_array[0]);
            }
            pointer end()
            {
                return (&_array[_size]);
            }

        protected:
            value_type      *_array;
            allocator_type  _alloc;
            size_type       _size;
            size_type       _capacity;                
    };
}

#endif