/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:18:45 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:15:22 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "color.h"
#include <iostream>

class ICharacter;
class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(AMateria const &amateria);
		virtual ~AMateria();
		AMateria(std::string const & type);
		AMateria &operator=(AMateria const &materia);
		void	setType(std::string type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif