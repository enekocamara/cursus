#include "Form.hpp"
#include <stdexcept>

Form::Form(): _name("unspecified"), _gradeSign(1), _gradeExe(1), _signed(false)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(const std::string name, int gradeSign, int gradeExe):_name(name), _gradeSign(gradeSign), _gradeExe(gradeExe), _signed(false)
{
	std::cout << GREEN << name <<"'s personalized Form constructor called" << RESET << std::endl;
	if (gradeSign < 1 || gradeExe < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExe > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &form): _name(form.getName()), _gradeSign(form.getGradeSign()), _gradeExe(form.getGradeExe()), _signed(form.getSigned())
{
	std::cout << GREEN << _name <<"'s copy constructor called" << RESET << std::endl;
	if (_gradeSign < 1 || _gradeExe < 1)
		throw Form::GradeTooHighException();
	if (_gradeSign > 150 ||_gradeExe > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeExe() const
{
	return (_gradeExe);
}

int Form::getGradeSign() const
{
	return (_gradeSign);
}

Form &Form::operator=(Form const &form)
{
	_signed = form.getSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << std::endl << "\tSigned =  " << form.getSigned() << std::endl <<
	"\tGradeSign = " << form.getGradeSign() << std::endl << "\tGradeExe = " << form.getGradeExe() << std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade was too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade was too low");
}
