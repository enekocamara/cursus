/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:17:35 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/14 12:49:59 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact(void)
{
	//std::cout << "Constructor" << std::endl;
	return ;
}
void	Contact::ft_input(void)
{
	std::cout << "Introduce name: ";
	std::getline(std::cin, _name);
	std::cout << "Introduce surname: ";
	std::getline(std::cin, _surname);
	std::cout << "Introduce nickname: ";
	std::getline(std::cin, _nickname);
	std::cout << "Introduce phone number: ";
	std::getline(std::cin, _phone);
	std::cout << "Introduce  darkest secret: ";
	std::getline(std::cin, _darkestSecret);
	std::cout << std::endl <<  "Contact added" << std::endl << std::endl;
}

void	Contact::ft_print_contact(void) const
{
	
	std::cout << std::endl << "-----------------" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Surname: " << _surname << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone: " << _phone << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
	std::cout << "-----------------" << std::endl << std::endl;
}

void	Contact::ft_print_colum(std::string str) const
{
	if (str.size() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << str;
	}
}

void	Contact::ft_print_index(int index) const
{
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << index;
	std::cout << " | ";
	ft_print_colum(_name);
	std::cout << " | ";
	ft_print_colum(_surname);
	std::cout << " | ";
	ft_print_colum(_nickname);
	std::cout << std::endl;
}

void	Contact::ft_set_phone(std::string str)
{
	_phone = str;
}
void	Contact::ft_set_darkestSecret(std::string str)
{
	_darkestSecret = str;
}
void	Contact::ft_set_surname(std::string str)
{
	_surname = str;
}
void	Contact::ft_set_name(std::string str)
{
	_name = str;
}
void	Contact::ft_set_nickname(std::string str)
{
	_nickname = str;
}

std::string Contact::ft_get_phone(void) const
{
	return(_phone);
}

std::string Contact::ft_get_nickname(void) const
{
	return(_nickname);
}

std::string Contact::ft_get_darkestSecret(void) const
{
	return(_nickname);
}


std::string Contact::ft_get_surname(void) const
{
	return(_surname);
}

std::string Contact::ft_get_name(void) const
{
	return(_name);
}