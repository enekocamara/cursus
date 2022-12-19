/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:06:57 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/10 12:11:21 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog const &dog);
		Dog &operator=(Dog const &dog);
		std::string getBrain(int i) const;
		void	setBrain(int i, std::string idea);
		void	makeSound() const;
	private:
		Brain *_brain;
};

#endif