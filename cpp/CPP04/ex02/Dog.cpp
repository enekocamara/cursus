/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:04:57 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:05:58 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	Animal::type = "Dog";
	std::cout << BLUE << "  Dog constructor called" << RESET<< std::endl;
	_brain = new Brain();
}
Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
	delete _brain;
}

Dog &Dog::operator=(Dog const &dog)
{
	std::cout << "Dog Assignation constructor called" << std::endl;
	type = dog.getType();
	delete _brain;
	_brain = new Brain(*dog._brain);
	return (*this);
}

Dog::Dog(Dog const &dog)
{
	std::cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
	*this = dog;
	_brain = new Brain(*dog._brain);
}

std::string Dog::getBrain(int i) const
{
	return (_brain->getIdea(i));
}

void Dog::setBrain(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

void	Dog::makeSound() const
{
	std::cout << "	Wau Wau Wau" << std::endl;
}