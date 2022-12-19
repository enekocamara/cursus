/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:26:20 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/25 13:18:45 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class 	Point
{
	public:
		Point();
		Point(Point const &point);
		~Point();
		Point(float x, float y);
		Point &operator=(Point const &point);
		Fixed get_x() const;
		Fixed get_y() const;
		void set_x(Fixed const num);
		void set_y(Fixed const num);
	
	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);