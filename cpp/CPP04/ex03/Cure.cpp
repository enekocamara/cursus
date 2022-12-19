/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:23:33 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:23:06 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << CYAN << "  Cure constructor called" << RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << RED << "Cure destructor called" << RESET << std::endl;
}

Cure &Cure::operator=(Cure const &cure)
{
	std::cout << CYAN << "  Cure assignation operator called" << RESET << std::endl;
	this->type = cure.getType();
	return (*this);
}


AMateria* Cure::clone()const
{
	AMateria *clone = new Cure();
	clone->setType(this->type);
	return(clone);
}

void	Cure::setType(std::string type)
{
	this->type = type;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "	* heals " << target.getName() << "’s wounds *" << std::endl;
}
