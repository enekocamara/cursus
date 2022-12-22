/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:48:20 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/22 17:59:38 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

Double::Double()
{
   _exceptionTrue = 0;
  //  std::cout << GREEN << "Double standard constructor called" << std::endl;
}

Double::~Double()
{
   // std::cout << GREEN << "Double standard destructor called" << std::endl;
}

void Double::setValue(double value)
{
    _value = value;
}

void Double::assignException(std::string &exception)
{
    _exception = exception;
    _exceptionTrue = 1;
}