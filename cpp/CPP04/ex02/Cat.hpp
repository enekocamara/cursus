/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:06:57 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/10 12:09:31 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat const &cat);
		Cat &operator=(Cat const &c);
		std::string getBrain(int i) const;
		void	setBrain(int i, std::string idea);
		void	makeSound() const;
	private:
		Brain *_brain;
};

#endif