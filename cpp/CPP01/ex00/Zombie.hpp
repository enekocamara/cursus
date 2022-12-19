/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:16:26 by ecamara           #+#    #+#             */
/*   Updated: 2022/06/20 09:55:14 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //


//#include <string.h>
#include <iostream>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
		void	setName(std::string name);
		void randomChump(std::string name);
		Zombie* newZombie(std::string name);

	private:
		std::string _name;
};

#endif