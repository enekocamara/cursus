/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 10:33:38 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << GREEN <<"Animal constructor called" << RESET <<std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "    Animal destructor called"<< RESET << std::endl;
}

Animal::Animal(Animal const &animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(Animal const &animal)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->type =  animal.getType();
	return *this;
}


void	Animal::makeSound(void)	const
{
	std::cout << ".,.,." << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
