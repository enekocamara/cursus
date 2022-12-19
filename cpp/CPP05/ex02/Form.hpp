/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:43 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/14 11:30:09 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "color.h"

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const std::string name, int gradeSign, int gradeExe);
		Form(Form const &Form);
		virtual ~Form();

		Form &operator=(Form const &Form);

		void	beSigned(const Bureaucrat &bureaucrat);
		bool	getSigned()const;
		int getGradeSign()const;
		int getGradeExe()const;
		std::string getName()const;
		virtual void	execute(Bureaucrat const & executor) const;
		class GradeTooHighException: public std::exception
		{
				virtual const char* what() const throw();//se hereda de std::exception y se redefine
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();//se hereda de std::exception y se redefine
		};
		class NotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
	protected:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExe;
		bool				_signed;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif