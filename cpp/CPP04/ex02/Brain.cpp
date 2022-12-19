/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:29:00 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 10:34:25 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int i = -1;
	while (++i < 100)
		_ideas[i] = "Brain Nº" + std::to_string(i) + " present";
	std::cout << CYAN << "    Brain constructor called" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "  Brain destructor called" << RESET << std::endl;
}

Brain::Brain(Brain const &brain)
{
	std::cout << CYAN << "Brain copy constructor called" << RESET << std::endl;
	*this = brain;
}

std::string Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
}

Brain &Brain::operator=(Brain const &brain)
{
	int	i = 0;
	std::cout << CYAN << "Brain assignation constructor called" << RESET << std::endl;
	while (i < 100)
	{
		this->setIdea(i, brain.getIdea(i));
		i++;
	}
	return (*this);
}