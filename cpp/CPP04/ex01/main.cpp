/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:51:05 by ecamara           #+#    #+#             */
/*   Updated: 2022/11/23 10:53:59 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int i = 0;
	Animal *animal[20];
	while (i < 10)
	{
		animal[i] = new Dog();
		animal[i]->makeSound();
		i++;
	}
	std::cout << std::endl;
	while (i < 20)
	{
		animal[i] = new Cat();
		animal[i]->makeSound();
		i++;
	}
	i--;
	while (i >= 0)
	{
		delete(animal[i]);
		i--;
	}
	std::cout << std::endl;
	Cat cat = Cat();
	Cat cat2 = Cat();
	cat.setBrain(0, "Im cat1");
	cat2 = cat;
	std::cout << "    "<<cat2.getBrain(0) << std::endl;
	return 0;
}
/*
int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
}*/