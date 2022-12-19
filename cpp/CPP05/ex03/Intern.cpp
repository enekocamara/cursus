/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:14:45 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/16 12:03:47 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	_dictionary[0] = "presidential pardon";
	_dictionary[1] = "robotomy request";
	_dictionary[2] = "shrubbery creation";
	_funct[0] = &Intern::formP;
	_funct[1] = &Intern::formR;
	_funct[2] = &Intern::formS;
}

Intern::~Intern()
{
	std::cout << RED << "Intern default destructor called" << RESET << std::endl;
}

Intern::Intern(Intern const &intern)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(Intern const &intern)
{
	std::cout << "Intern cory operator called" << std::endl;
	(void) intern;
	return (*this);
}

Form *Intern::makeForm(std::string form, std::string target)
{
	int	i;

	i = 0;
	std::transform(form.begin(), form.end(), form.begin(),::tolower);
	while (i < 3)
	{
		if (form == _dictionary[i])
			return ((this->*_funct[i])(target));
			i++;
	}
	std::cout << "\t" << "Failure" << std::endl;
	throw PassedFormInvalid();
}

Form *Intern::formP(std::string target)
{
	Form *temp = new PresidentialPardonForm(target);
	if (!temp)
	{
		throw NewFailureException();
	}
	return (temp);
}

Form *Intern::formS(std::string target)
{
	Form *temp = new ShrubberyCreationForm(target);
	if (!temp)
	{
		throw NewFailureException();
	}
	return (temp);
}

Form *Intern::formR(std::string target)
{
	Form *temp = new RobotomyRequestForm(target);
	if (!temp)
	{
		throw NewFailureException();
	}
	return (temp);
}

const char* Intern::NewFailureException::what() const throw()
{
	return ("\tNew failed");
}

const char* Intern::PassedFormInvalid::what() const throw()
{
	return ("\tPassed form name was invalid");
}
