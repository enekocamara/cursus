/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:00:36 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/15 11:11:21 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	_hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	*this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	this->_name = fragTrap._name;
	this->_attackDamage = fragTrap._attackDamage;
	this->_hitpoints = fragTrap._hitpoints;
	this->_energyPoints = fragTrap._energyPoints;
	std::cout << "Copy constructor called: " << _name << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void)const
{
	std::cout << _name << " has recuested a high fives." << std::endl;
}
