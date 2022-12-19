/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:48:46 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/14 11:13:08 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include <iostream>
#include "Form.hpp"
#include <stdlib.h>

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &ref);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &ref);
		std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
		class FailureToRobotomyze : public std::exception
		{
			virtual const char* what() const throw();
		};
	private:
		const std::string _target;
};

#endif