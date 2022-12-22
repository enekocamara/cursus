/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:48:20 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/22 17:59:52 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int.hpp"

Int::Int()
{
    _exceptionTrue = 0;
  //  std::cout << GREEN << "Int standard constructor called" << std::endl;
}

Int::~Int()
{
   // std::cout << GREEN << "Int standard destructor called" << std::endl;
}

void Int::setValue(int value)
{
    _value = value;
}

int Int::getInt() const
{
    return (_value);
}

void Int::assignException(std::string &exception)
{
    _exception = exception;
    _exceptionTrue = 1;
}