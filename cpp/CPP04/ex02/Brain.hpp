/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:29:09 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 10:31:54 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string.h>
#include "color.h"

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain const &brain);
		std::string getIdea(int i) const;
		Brain &operator=(Brain const &brain);
		void setIdea(int i, std::string idea);
	private:
		std::string	_ideas[100];
};

#endif