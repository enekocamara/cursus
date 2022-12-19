/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:43:12 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/06 12:21:23 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Player1("Player1");
	ClapTrap Player2("Player2");

	Player1.attack(Player2.getName());
	Player2.takeDamage(Player1.getAttack());
	Player2.beRepaired(10000000);
	return 0;
}
