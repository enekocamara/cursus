/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:23:20 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/21 10:48:26 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		
	
	protected:
		//using FragTrap::_hitpoints;
		//using FragTrap::_attackDamage;
		using ScavTrap::_energyPoints;
		std::string _name;
	
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		void whoAmI();
		using ScavTrap::attack;
		int	getEnergyPoints(void);
		int	getHitpoints(void);
};

#endif

