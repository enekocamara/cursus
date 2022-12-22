/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:48:20 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/22 17:59:45 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

Float::Float()
{
    _exceptionTrue = 0;
   // std::cout << GREEN << "Float standard constructor called" << std::endl;
}

Float::~Float()
{
  //  std::cout << GREEN << "Float standard destructor called" << std::endl;
}

void Float::setValue(float value)
{
    _value = value;
}

void Float::assignException(std::string &exception)
{
    _exception = exception;
    _exceptionTrue = 1;
}