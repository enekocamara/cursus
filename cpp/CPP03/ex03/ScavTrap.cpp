/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:00:36 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/21 10:28:37 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitpoints = 100;
    this->_energyPoints = 50;
   this->_attackDamage = 20;
   this->_gate = false;
	std::cout << "ScapTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_gate = false;
	std::cout << "ScapTrap named constructor called" << std::endl;
	std::cout << "hitpoints: " << _hitpoints << std::endl << "energypoints: " << _energyPoints << std::endl << "attack: " << _attackDamage << std::endl;
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
