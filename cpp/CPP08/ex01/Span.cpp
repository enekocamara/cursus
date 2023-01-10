/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:28:01 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/03 13:49:49 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>

Span::Span(unsigned int max)
{
    _len = 0;
    _maxLen = max;
    _shortestSpan = -1;
    _shortestSpan = -1;
    _min = 2147483647;
    _max = -2147483648;
}

Span::~Span()
{

}

void Span::addNumber(int num)
{
    if (_len == _maxLen)
        throw MaxReached();
    _vec.push_back(num);
    _len++;
    if (_len == 1)
    {
        _min = num;
        _max = num;
    }
    else
    {
        if (num < _min)
        {
            _min = num;
            _longestSpan = _max - _min;
        }
        if (num > _max)
        {
            _max = num;
        }
    }
}

int Span::longestSpan()
{
    if (_len == 0 || _len == 1)
        throw SpanError();
    return (_max  - _min);
}

int Span::shortestSpan()
{
    int currentSpan;

    if (_len == 0 || _len == 1)
        throw SpanError();
    currentSpan = longestSpan();
    for(intIterator it = _vec.begin(); it != _vec.end(); it++)
    {
        for(intIterator it2 = _vec.begin(); it2 != _vec.end(); it2++)
        {
            if (std::abs(*it - *it2) < currentSpan && *it - *it2 != 0)
                currentSpan = std::abs(*it - *it2);
        }
    }
    return (currentSpan);
}
