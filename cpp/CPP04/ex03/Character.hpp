/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:56:15 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/19 10:33:59 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		~Character();
		Character(std::string _name);
		Character(Character const &character);
		Character &operator=(Character const &character);

		std::string const & getName() const;
		AMateria *getMateria(int index) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		AMateria *_inventory[4];
		AMateria *_trash[100];
		std::string _name;
};

#endif