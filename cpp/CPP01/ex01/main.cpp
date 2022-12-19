/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:28:22 by ecamara           #+#    #+#             */
/*   Updated: 2022/06/20 10:23:38 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	i;
	int	j;
	Zombie *zombieHorde;

	j = 0;
	i = 10;
	zombieHorde = zombieHorde->zombieHorde(i, "JUAN");
	while (j < i)
	{
		zombieHorde[j].announce();
		j++;
	}
	delete [] zombieHorde;
	return (0);
}