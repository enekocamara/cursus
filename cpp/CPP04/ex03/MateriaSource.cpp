/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:04:02 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:27:18 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << GREEN <<"MateriaSource constructor called" << RESET << std::endl;
	int i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	int i = -1;
	std::cout << RED << "MateriaSource destructor called" << RESET << std::endl;
	while (++i < 4)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	int i = -1;
	while (++i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = materia;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	int i = -1;
	while (++i < 4)
	{
		if (_inventory[i]->getType() == type)
		{
			return (_inventory[i]->clone());
		}
	}
	return (0);
}

