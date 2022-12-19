/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:25:25 by ecamara           #+#    #+#             */
/*   Updated: 2022/06/20 10:18:07 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name)
{
	Zombie *zombieHorde;
	int	i;

	zombieHorde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombieHorde[i]._name = name;
		i++;
	}
	return (&zombieHorde[0]);
}