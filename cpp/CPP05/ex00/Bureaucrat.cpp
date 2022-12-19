#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat()
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):  _grade(grade), _name(name)
{
	std::cout << GREEN << name <<"'s personalized bureaucrat constructor called" << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	_grade = bureaucrat.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
	out << BLUE << "Bureaucrat " << b.getName() << " has a grade of: " << RESET << b.getGrade();
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade was too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade was too low");
}

void	Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}