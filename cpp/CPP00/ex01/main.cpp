/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:50:01 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/14 13:21:57 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_list.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>

void	ft_cases(std::string str, Contact_list *PhoneBook)
{
	if (!str.compare("EXIT"))
		exit (0);
	else if (!str.compare("SEARCH"))
		PhoneBook->ft_search();
	else if (!str.compare("ADD"))
		PhoneBook->ft_add_new_contact();
	else
		std::cout << "Input incorrect. EXIT SEARCH ADD." << std::endl;
}

int main(void)
{
	int				cont_num;
	std::string		input;
	Contact_list	PhoneBook;

	cont_num = 0;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input.empty() || input[0] == '\0')
			continue ;
		ft_cases(input, &PhoneBook);
	}
	return (0);
}