/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:22:56 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/21 10:27:43 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():  ScavTrap(), FragTrap()
{
	ClapTrap::_name = "Unasigned claptrap name";
	std::cout << "Diamond constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "Diamond named constructor called" << std::endl;
	std::cout << "hitpoints: " << _hitpoints << std::endl << "energypoints: " << _energyPoints << std::endl << "attack: " << _attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "-> My Diamond name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

int	DiamondTrap::getEnergyPoints()
{

	return (_energyPoints);
}

int	DiamondTrap::getHitpoints()
{

	return (_hitpoints);
}