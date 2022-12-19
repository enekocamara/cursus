/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:44:21 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/05 17:07:20 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		Fixed(Fixed const &num);

		Fixed &operator=(Fixed const &num);
		Fixed operator*(Fixed const &num) const;
		Fixed operator/(Fixed const &num) const;
		Fixed operator+(Fixed const &num) const;
		Fixed operator-(Fixed const &num) const;

		bool operator<(Fixed const &unm) const;
		bool operator>(Fixed const &num) const;
		bool operator<=(Fixed const &num) const;
		bool operator>=(Fixed const &num) const;
		bool operator!=(Fixed const &num) const;
		bool operator==(Fixed const &num) const;

		Fixed operator++(int);	//i++
		Fixed &operator++(void); //++i
		Fixed operator--(int);	//i--
		Fixed &operator--(void);	//--i

		static Fixed const &max(Fixed const &num1, Fixed const &num2);
		static Fixed &max(Fixed &num1, Fixed &num2);
		static Fixed const &min(Fixed const &num1, Fixed const &num2);
		static Fixed &min(Fixed &num1, Fixed &num2);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int	  toInt(void) const;
	private:
		int				_num;
		static int const _rawBits;
};

std::ostream &operator<<(std::ostream &out, Fixed const &num);

#endif