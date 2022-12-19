/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:54:30 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/25 15:26:47 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	w1;
	Fixed	w2;
	Point	a1 = a;
	Point	c1 = c;
	if (c1.get_y() == a1.get_y())
	{
		Point temp = a1;
		a1 = c1;
		c1 = temp;
	}
	w1 = (a1.get_x() * (c1.get_y() - a1.get_y()) + (point.get_y() - a1.get_y()) * (c1.get_x() - a1.get_x()) - point.get_x() * (c1.get_y() - a1.get_y()) )/ 
		((b.get_y() - a1.get_y()) * (c1.get_x() - a1.get_x()) - (b.get_x() - a1.get_x()) * (c1.get_y() - a1.get_y()));
	
	w2 = (point.get_y() - a1.get_y() - w1 * (b.get_y() - a1.get_y())) / 
		(c1.get_y() - a1.get_y());
	if (w1 > 0 && w2 > 0 && w1 + w2 < 1)
		return (true);
	return (false);
}