/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:51:35 by ecamara           #+#    #+#             */
/*   Updated: 2022/06/20 09:56:55 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie;
	Zombie *zombie2;

	zombie2 = zombie.newZombie("jack");
	zombie2->announce();
	zombie.randomChump("nice");
	delete zombie2;
	return (0);
}