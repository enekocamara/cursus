/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_list.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:17:00 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/14 13:20:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_list.hpp"
#include "Contact.hpp"

Contact_list::Contact_list()
{
	_last_contact = 1;
	_contact_num = 0;
	_last_num = 0;
}

void	Contact_list::ft_add_new_contact(void)
{
	
	_contacts[_last_num].ft_input();
	if (_last_num == 2)
		_last_num = 0;
	else
		_last_num++;
}


void	Contact_list::ft_search(void)
{
	int i;
	std::string temp;
	char *str;

	i = 0;
	while (i < 3)
	{
		_contacts[i].ft_print_index(i);
		i++;
	}
	std::cout << std::endl;
	while (temp.size() == 0)
	{
		std::cout << "Enter number: ";
		std::getline(std::cin, temp);
	}
	if (temp.size() > 1 || temp[0] < '0' || temp[0] > '7')
		std::cout << "Input invalid" << std::endl;
	else
		_contacts[atoi(temp.c_str())].ft_print_contact();
}
