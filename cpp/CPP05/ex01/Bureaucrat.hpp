#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>
#include <stdexcept>
#include "color.h"
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &bureaucrat);

		Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
	
		int	getGrade()const;
		const std::string getName() const;
		void	increaseGrade();
		void	decreaseGrade();
		void	signForm(Form &form);

		class GradeTooHighException: public std::exception
		{
				virtual const char* what() const throw();//se hereda de std::exception y se redefine
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();//se hereda de std::exception y se redefine
		};
	private:
		int	_grade;
		const std::string _name;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif