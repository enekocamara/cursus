/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:55:03 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/14 11:21:20 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdexcept>
#include <fstream>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(): Form("Unkown", 75, 45), _target("Unspecified target")
{
	std::cout << GREEN << "FormRobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):Form("Unkown", 75, 45), _target(target)
{
	std::cout << GREEN << _name <<"'s personalized FormRobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref): Form(ref.getName(), ref.getGradeSign(), ref.getGradeExe()), _target(ref.getTarget())
{
	_signed = ref.getSigned();
	std::cout << GREEN << _name <<"'s copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	_signed = ref.getSigned();
	return *this;
}
std::string RobotomyRequestForm::getTarget()const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int i = (rand() % 2 == 0);
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
	if (i)
	{
		std::cout << "\t" << _target << " has bee robotomyzed successfully." << std::endl;
	}
	else
	{
		std::cout << RED << "\tFailure." << RESET << std::endl;
		throw FailureToRobotomyze();
	}
}

const char*  RobotomyRequestForm::FailureToRobotomyze::what() const throw()
{
	return ("\tFailure to robotyze");
}