/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:55:03 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/14 12:27:20 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Unkown", 145, 137), _target("Unspecified target")
{
	std::cout << GREEN << "FormShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):Form("Unkown", 145, 137), _target(target)
{
	std::cout << GREEN << _name <<"'s personalized FormShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref): Form(ref.getName(), ref.getGradeSign(), ref.getGradeExe()), _target(ref.getTarget())
{
	_signed = ref.getSigned();
	std::cout << GREEN << _name <<"'s copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	_signed = ref.getSigned();
	return *this;
}
std::string ShrubberyCreationForm::getTarget()const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
	{
		std::cout << RED << "\tFailure" << RESET << std::endl;
		throw NotSignedException();
	}
	if (executor.getGrade() > _gradeExe)
	{
		std::cout << RED << "\tFailure" << RESET << std::endl;
		throw GradeTooLowException();
	}
	std::cout << GREEN << "\tSuccessful ShrubberyCreation" << RESET << std::endl;
	std::ofstream file(_target + "_shrubbery", std::ios::out);
	file		<< "            .        +          .      .          .\n"
				<< "     .            _        .                    .\n"
				<< "  ,              /;-._,-.____        ,-----.__\n"
				<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
				<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
				<< "                      ,    `./  \\:. `.   )==-'  .\n"
				<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
				<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
				<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
				<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
				<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
				<< "              \\:  `  X` _| _,\\/'   .-'\n"
				<< ".               \":._:`\\____  /:'  /      .           .\n"
				<< "                    \\::.  :\\/:'  /              +\n"
				<< "   .                 `.:.  /:'  }      .\n"
				<< "           .           ):_(:;   \\           .\n"
				<< "                      /:. _/ ,  |\n"
				<< "                   . (|::.     ,`                  .\n"
				<< "     .                |::.    {\n"
				<< "                      |::.\\  \\ `.\n"
				<< "                      |:::(\\    |\n"
				<< "              O       |:::/{ }  |                  (o\n"
				<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
				<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~\n";
	file.close();
}
