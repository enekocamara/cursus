/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:25:28 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/13 10:50:21 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class	Karen
{
	public:
		Karen();
		~Karen();
		std::string messages[4];
		void	(Karen::*funct[4])(void);
		void	complain(std::string level);
	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
};

#endif