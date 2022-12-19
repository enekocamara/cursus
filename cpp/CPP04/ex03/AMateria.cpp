/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:59:38 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:26:10 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria constructor called" << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED << "  AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(AMateria const &amateria)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = amateria;
}

AMateria &AMateria::operator=(AMateria const &amateria)
{
	std::cout << "AMateria assign operator called" << std::endl;
	type = amateria.getType();
	return (*this);
}

std::string const &AMateria::getType()const
{
	return (type);
}

void AMateria::setType(std::string type)
{
	this->type = type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria has been used by " << target.getName() << std::endl;
}
