/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:28:09 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/05 10:49:24 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{
	return ;	
};

HumanB::HumanB(std::string name) : _name(name){};

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
	return ;
};

HumanB::~HumanB(void)
{
	return ;
};

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	return ;
};

void	HumanB::attack(void) const
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
};