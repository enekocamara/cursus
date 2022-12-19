/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:00:36 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/15 11:01:31 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _gate = false;
	std::cout << "ScapTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _gate = false;
	std::cout << "ScapTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	*this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	this->_name = scavTrap._name;
	this->_attackDamage = scavTrap._attackDamage;
	this->_energyPoints = scavTrap._energyPoints;
	this->_hitpoints = scavTrap._hitpoints;
	std::cout << "Copy constructor called: " << _name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScapTrap destructor called" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	_gate = true;
	std::cout << _name << "has entered gate keeper mode." << std::endl;
}
