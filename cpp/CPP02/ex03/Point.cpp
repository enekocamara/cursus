/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:26:07 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/25 15:24:52 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){}

Point::Point(float x, float y) : _x(x), _y(y){}

Point::Point(Point const &point): _x(point.get_x()),  _y(point.get_y())
{
	/*this->set_x(point.get_x());
	this->set_y(point.get_y());*/
}

Point::~Point(void)
{
	return ;
}

Fixed Point::get_x() const
{
	return (_x);
}

Fixed Point::get_y() const
{
	return (_y);
}
Point &Point::operator=(Point const &point)
{
	Fixed x;
	Fixed y;
	x = point.get_x();
	y = point.get_y();
	Point a(x.toFloat(),y.toFloat());
	return (*this);
}
/*
void Point::set_x(Fixed const num)
{
	_x.setRawBits(num.getRawBits());
}

void Point::set_y(Fixed const num)
{
	_y.setRawBits(num.getRawBits());
}*/