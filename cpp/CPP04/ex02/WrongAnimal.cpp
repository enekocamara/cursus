/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/06 16:23:39 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void)	const
{
	std::cout << getSound() << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

std::string WrongAnimal::getSound()	const
{
	if (getType() == "WrongCat")
		return ("Meow Meow Meow");
	return ("Unintelligible sound");
}