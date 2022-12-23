/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:48:20 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 12:32:05 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Char.hpp"

Char::Char()
{
   _exceptionTrue = 0;
  //  std::cout << GREEN << "Char standard constructor called" << std::endl;
}

Char::~Char()
{
  //  std::cout << GREEN << "Char standard destructor called" << std::endl;
}

void Char::setValue(char value)
{
    _value = value;
}

void Char::assignException(std::string exception)
{
    _exception = exception;
    _exceptionTrue = 1;
}

char Char::getChar()const
{
    return (_value);
}

int Char::getExceptionTrue()const
{
    return (_exceptionTrue);
}

std::string Char::getException()const
{
    return (_exception);
}