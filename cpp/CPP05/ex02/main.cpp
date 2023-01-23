#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat asianParent("AsianParent", 1);
	{
		
	}
	ShrubberyCreationForm nice(std::string("nice"));
	RobotomyRequestForm nice2(std::string("nice2"));
	PresidentialPardonForm nice3(std::string("nice3"));
	try
	{
		nice.execute(asianParent);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	asianParent.signForm(nice);
	try
	{
		nice.execute(asianParent);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		nice2.execute(asianParent);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	asianParent.signForm(nice2);
	try
	{
		nice2.execute(asianParent);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		nice3.execute(asianParent);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	asianParent.signForm(nice3);
	try
	{
		nice3.execute(asianParent);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		asianParent.executeForm(nice3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}