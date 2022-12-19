/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_list.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:20:21 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/14 12:51:10 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_list_HPP
# define Contact_list_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class Contact_list
{
	public:

		Contact_list();
		void	ft_add_new_contact(void);
		int		ft_search_contact(std::string str);
		void	ft_search(void);
		void	ft_add_contact(void);
		void	ft_set_last_contact(int);
		int		ft_get_last_contact(void);

	private:
		int	_last_contact;
		int	_contact_num;
		int	_last_num;
		Contact _contacts[3];
};

#endif
