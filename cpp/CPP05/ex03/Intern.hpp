/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:15:32 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/16 11:57:47 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(Intern const &intern);
		~Intern();
	
		Intern &operator=(Intern const &intern);
		Form *makeForm(std::string form, std::string target);
		class NewFailureException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class PassedFormInvalid : public std::exception
		{
			virtual const char* what() const throw();
		};
	private:
		std::string _dictionary[3];
		Form	*(Intern::*_funct[3])(std::string target);
		Form *formP(std::string target);
		Form *formS(std::string target);
		Form *formR(std::string target);
		//Form	*(Intern::*_funct[3])(std::string target);
};