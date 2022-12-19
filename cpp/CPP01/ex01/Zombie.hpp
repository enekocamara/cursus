/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:16:26 by ecamara           #+#    #+#             */
/*   Updated: 2022/06/20 10:12:26 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	public:
		Zombie();
		~Zombie(void);
		void	announce(void) const;
		void	setName(std::string name);
		Zombie* zombieHorde( int N, std::string name);
		
	private:
		std::string _name;
};

#endif