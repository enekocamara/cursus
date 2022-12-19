/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:53:23 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 10:31:27 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>
#include "Brain.hpp"
#include "color.h"

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(Animal const &animal);
		Animal &operator=(Animal const &animal);
		std::string getType() const;
		virtual void	makeSound() const = 0;
	protected:
		std::string type;
};
#endif