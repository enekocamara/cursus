/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:46:41 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/24 15:59:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_rawBits = 8;

Fixed::Fixed(void): _num(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const value): _num(0)
{
	
	//std::cout << "Int constructor called" << std::endl;
	setRawBits(value * (1 << _rawBits));
	return ;
}

Fixed::Fixed(float const value): _num(0)
{
	//std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << _rawBits)));
	return ;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &num)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_num = num.getRawBits();
	return ;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_num);
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "Assignation operator called" << std::endl;
	_num = raw;
}

Fixed &Fixed::operator=(Fixed const &num)
{
	this->setRawBits(num.getRawBits());
	return (*this);
}


Fixed Fixed::operator+(Fixed const &num) const
{
	Fixed ans;
	ans.setRawBits(this->getRawBits() + num.getRawBits());
	return (ans);
}

Fixed Fixed::operator-(Fixed const &num) const
{
	Fixed ans;
	ans.setRawBits(this->getRawBits() - num.getRawBits());
	return (ans);
}

Fixed Fixed::operator*(Fixed const &num) const
{
	Fixed ans;
	ans.setRawBits(this->getRawBits() * num.getRawBits() / (1 << _rawBits));
	return (ans);
}

Fixed Fixed::operator/(Fixed const &num) const
{
	Fixed ans;
	ans.setRawBits((roundf(this->getRawBits()) / num.getRawBits()) * (1 << _rawBits));
	return (ans);
}

bool Fixed::operator<(Fixed const &num) const
{
	if (this->getRawBits() < num.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(Fixed const &num) const
{
	if (this->getRawBits() > num.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &num) const
{
	if (this->getRawBits() <= num.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &num) const
{
	if (this->getRawBits() >= num.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &num) const
{
	if (this->getRawBits() == num.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &num) const
{
	if (this->getRawBits() != num.getRawBits())
		return (true);
	return (false);
}

std::ostream &operator<<(std::ostream &out, Fixed const &num)
{
	out << num.toFloat();
	return (out);
}

int Fixed::toInt( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_num / (1 << _rawBits));
}

float Fixed::toFloat( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (roundf(_num) / (1 << _rawBits));
}

Fixed Fixed::operator++(int)
{
	Fixed ans(*this);
	this->_num = _num + (1 << 8);
	return (ans);
}

Fixed &Fixed::operator++(void)
{
	this->_num = _num + (1 << 8);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed ans(*this);
	this->_num = _num - (1 << 8);
	return (ans);
}

Fixed &Fixed::operator--(void)
{
	this->_num = _num - (1 << 8);
	return (*this);
}

Fixed const &Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed const &Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}