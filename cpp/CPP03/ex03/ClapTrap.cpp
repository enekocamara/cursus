/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:44:14 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/21 10:13:15 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitpoints(10), _attackDamage(0), _energyPoints(10)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name) , _hitpoints(10), _attackDamage(0), _energyPoints(10)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap){
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitpoints = clapTrap._hitpoints;
	this->_energyPoints = clapTrap._energyPoints;
	std::cout << "Copy constructor called: " << this->_name << std::endl;
	return(*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::string ClapTrap::getName() const
{
	return(_name);
}

int ClapTrap::getAttack() const
{
	return(_attackDamage);
}

void	ClapTrap::setAttack(int value)
{
	_attackDamage = value;
}


void ClapTrap::attack(std::string const &target)
{
	_energyPoints -= 1;
	std::cout << this->getName() << " has attacked " << target << ", causing " << _attackDamage << " points of damage!" << std::endl << "IT WAS SUPER EFFECTIVE" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name << " has lost " << amount << " points of HP." << std::endl;
	_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << _name << " has restored " << amount << " of HP." << std::endl;
	_hitpoints += amount;
}