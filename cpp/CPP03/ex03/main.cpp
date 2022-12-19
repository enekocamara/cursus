/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:43:12 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/21 09:41:33 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	Monster("Monster");

	Monster.whoAmI();
	Monster.getAttack();
	std::cout << Monster.getEnergyPoints() << " " <<  Monster.getHitpoints() << " " << Monster.getAttack() << std::endl;
	/*
	ClapTrap King("King");
	ClapTrap Queen("Queen");
	ClapTrap Bishop("Bishop");
	ScavTrap Tower("Tower");
	FragTrap Pawn("Pawn");
	
	Bishop.setAttack(9);
	Queen.setAttack(10);
	Bishop.attack("King");
	King.takeDamage(Bishop.getAttack());
	Bishop.attack("King");
	Tower.guardGate();
	King.takeDamage(0);
	Queen.attack("Bishop");
	Bishop.takeDamage(Queen.getAttack());
	King.beRepaired(10);
	Pawn.highFivesGuys();
	Queen.attack("Pawn");*/
	return (0);
}