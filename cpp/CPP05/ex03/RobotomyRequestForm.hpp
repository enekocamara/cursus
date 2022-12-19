/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:48:46 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/14 11:13:08 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &ref);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);
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