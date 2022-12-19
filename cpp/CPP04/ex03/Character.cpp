/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:01:04 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:28:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character()
{
	int	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
	i = -1;
	while (i < 100)
		_trash[i] = NULL;
	std::cout << GREEN << "Character constructor called" << RESET << std::endl;
}

Character::Character(std::string name)
{
	int	i = -1;
	_name = name;
	while (++i < 4)
		_inventory[i] = NULL;
	i = -1;
	while (++i < 100)
		_trash[i] = NULL;
	std::cout << GREEN << "Character constructor called" << RESET << std::endl;
}

Character::~Character()
{
	std::cout << RED <<  _name << " Character destructor called" << RESET << std::endl;
	int	i = -1;
	while (++i < 4)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	std::cout << RED << "  Inventory emptied" << RESET << std::endl;
	i = -1;
	while (++i < 100)
	{
		if (_trash[i] != NULL)
			delete _trash[i];
	}
	std::cout << RED << "    Trash emptied" << RESET << std::endl;
}

Character::Character(Character const &character)
{
	std::cout << GREEN << "Character copy constructor called" << RESET << std::endl;
	*this = character;
}


AMateria *Character::getMateria(int i) const
{
	return (_inventory[i]->clone());
}

std::string const &Character::getName() const
{
	return _name;
}

Character &Character::operator=(Character const &character)
{
	int i = -1;
    std::cout << GREEN <<"Character Assignation operator called" << RESET << std::endl;
	this->_name = character.getName();
    while (++i < 4)
    {
		this->_inventory[i] = character.getMateria(i);
        this->_inventory[i] = NULL;

    }
    i = -1;
    while (++i < 100)
        this->_trash[i] = NULL;
	return (*this);
}

void	Character::equip(AMateria *m)
{
	int	i = -1;
	while (++i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "	" << getName() << " inventory[" << i << "] = " << m->getType() << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	int	i;

	if (idx >=4 || idx < 0)
		return ;
	i = -1;
	while (_trash[++i])
		continue ;
	_trash[i] = _inventory[idx];
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter & target)
{
	if (idx < 4)
		_inventory[idx]->use(target);
}
