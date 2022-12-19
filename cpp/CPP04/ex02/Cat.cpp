/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:04:57 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 10:35:53 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << BLUE << "  Cat constructor called" << RESET << std::endl;
	_brain = new Brain();
	type = "Cat";
}
Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
	delete(_brain);
}
Cat::Cat(Cat const &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
	_brain = new Brain(*cat._brain);
	return ;
}
Cat &Cat::operator=(Cat const &cat)
{
	std::cout << BLUE <<"Cat Assignation operator called" << RESET << std::endl;
	type = cat.type;
	delete _brain;
	_brain = new Brain(*cat._brain);
	return (*this);
}

std::string Cat::getBrain(int i) const
{
	return (_brain->getIdea(i));
}

void Cat::setBrain(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

void	Cat::makeSound() const
{
	std::cout << "	Meow Meow Meow" << std::endl;
}