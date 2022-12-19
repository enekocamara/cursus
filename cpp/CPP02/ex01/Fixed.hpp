/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:44:21 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/05 16:35:11 by ecamara          ###   ########.fr       */
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