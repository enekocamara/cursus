/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:24:29 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/29 10:20:10 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	public:
		Contact(void);
		void		ft_input(void);
		void		ft_print_contact(void) const;
		void		ft_print_colum(std::string str) const;
		void		ft_print_index(int index) const;
		std::string ft_get_name(void) const;
		std::string ft_get_surname(void) const;
		std::string ft_get_phone(void) const;
		std::string ft_get_darkestSecret(void) const;
		std::string ft_get_nickname(void) const;
		void		ft_set_name(std::string);
		void		ft_set_surname(std::string);
		void		ft_set_phone(std::string);
		void		ft_set_darkestSecret(std::string str);
		void		ft_set_nickname(std::string str);

	private:
		std::string _name;
		std::string _surname;
		std::string _phone;
		std::string _darkestSecret;
		std::string _nickname;
};


#endif