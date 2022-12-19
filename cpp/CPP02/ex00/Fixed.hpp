/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:44:21 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/05 12:34:52 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &num);
		Fixed &operator=(Fixed const &num);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int				_num;
		static int const _rawBits;
};

#endif