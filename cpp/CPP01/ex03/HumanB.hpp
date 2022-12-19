/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:24:40 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/05 10:49:16 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(void);
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB(void);
		void		setWeapon(Weapon &weapon);
		void		attack(void) const;

	private:
		std::string	_name;
		Weapon 	*_weapon;
};

#endif