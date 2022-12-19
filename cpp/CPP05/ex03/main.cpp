#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern mike;
	Bureaucrat gigaChad("GigaChad", 1);
	try
	{
		Form *trial = mike.makeForm("presidential pardon", "unai black track");
		gigaChad.signForm(*trial);
		gigaChad.executeForm(*trial);
		delete trial;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form *trial = mike.makeForm("presidential pardons", "unai black track");
		gigaChad.executeForm(*trial);
		delete trial;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}