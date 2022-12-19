/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:46:41 by ecamara           #+#    #+#             */
/*   Updated: 2022/10/13 11:48:26 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_rawBits = 8;

Fixed::Fixed(void): _num(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &num)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_num = num.getRawBits();
	return ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_num);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "Assignation operator called" << std::endl;
	_num = raw;
}

Fixed &Fixed::operator=(Fixed const &num)
{
	this->setRawBits(num.getRawBits());
	return (*this);
}
