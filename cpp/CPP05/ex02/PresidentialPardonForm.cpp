/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:55:03 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/14 11:21:20 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <stdexcept>
#include <fstream>
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm(): Form("Unkown", 25, 5), _target("Unspecified target")
{
	std::cout << GREEN << "FormPresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):Form("Unkown", 25, 5), _target(target)
{
	std::cout << GREEN << _name <<"'s personalized FormPresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref): Form(ref.getName(), ref.getGradeSign(), ref.getGradeExe()), _target(ref.getTarget())
{
	_signed = ref.getSigned();
	std::cout << GREEN << _name <<"'s copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
	_signed = ref.getSigned();
	return *this;
}
std::string PresidentialPardonForm::getTarget()const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
	{
		std::cout << "\tFailure." << std::endl;
		throw NotSignedException();
	}
	if (executor.getGrade() > _gradeExe)
	{
		std::cout << "\tFailure" << std::endl;
		throw GradeTooLowException();
	}
	std::cout << "\t" << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
