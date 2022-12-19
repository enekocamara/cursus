/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:49:35 by ecamara           #+#    #+#             */
/*   Updated: 2022/06/20 10:29:07 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string name = "HI THIS IS BRAIN";
	std::string* namePTR = &name;
	std::string& nameREF = name;

	std::cout << &name << std::endl << namePTR << std::endl << &nameREF << std::endl;
	std::cout << (*namePTR) << std::endl << nameREF <<std::endl;
	return (0);
}