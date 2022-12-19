/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:51:05 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 11:06:29 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal *error = new Animal();
	//error->makeSound();
	//delete animal;
	
	int	i = 0;
	Animal *animal[20];
	while (i < 10)
	{
		animal[i] = new Dog();
		animal[i]->makeSound();
		i++;
	}
	while (i < 20)
	{
		animal[i] = new Cat();
		animal[i]->makeSound();
		i++;
	}
	while (--i >= 0)
	{
		delete(animal[i]);
	}
	Cat cat = Cat();
	Cat cat2 = Cat();
	cat.setBrain(0, "Im cat1");
	cat2 = cat;
	std::cout << "	" << cat2.getBrain(0) << std::endl;
	return 0;
}