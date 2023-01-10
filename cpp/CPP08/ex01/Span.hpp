/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:48:23 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/05 11:43:39 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    public:
        Span(unsigned int max);
        ~Span();
        
        void addNumber(int num);
        int    shortestSpan();
        int    longestSpan();
        void            setLongestSpan();
    private:
        int       _longestSpan;
        int       _shortestSpan;
        int                 _min;
        int                 _max;
        unsigned int       _len;
        unsigned int       _maxLen;
        std::vector<int>   _vec;

        class MaxReached: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Max capacity reached\n");
            }
        };
        class SpanError: public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Not enough numbers set\n");
            }
        };
        typedef std::vector<int>::iterator    intIterator;
};

#endif