/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:16:20 by ecamara           #+#    #+#             */
/*   Updated: 2022/06/20 10:08:32 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << _name << " was destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << "<" << _name << "> " <<  "Braiiiiiiinnnzzz..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}