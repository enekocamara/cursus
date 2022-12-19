/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:55:13 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:24:14 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	type = "ice";
	std::cout << BLUE << "  Ice constructor called" << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << RED << "Ice destructor called" << RESET << std::endl;
}

Ice &Ice::operator=(Ice const &Ice)
{
	std::cout << BLUE <<  "Ice assignation operator called" << RESET << std::endl;
	this->type = Ice.getType();
	return (*this);
}

AMateria* Ice::clone()const
{
	AMateria *clone = new Ice();
	clone->setType(this->type);
	return(clone);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "	* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
