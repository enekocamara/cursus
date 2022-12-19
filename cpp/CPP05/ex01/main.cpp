#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat emotinalDamage("Can't cook rice", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat neighbourKid("Can play piano Always tens", 150);
		Form asianParentDecree("asianParentAproval", 1, 1);
		neighbourKid.signForm(asianParentDecree);
		Bureaucrat asianParent("Not good enough mor study", 1);
		while (neighbourKid.getGrade() > 2)
		{
			std::cout << "study";
			neighbourKid.increaseGrade();
		}
		std::cout << neighbourKid.getGrade() << std::endl;
		neighbourKid.signForm(asianParentDecree);
		Form asianParentAverage("asianParentAverage", 1, 1);
		neighbourKid.signForm(asianParentAverage);
		asianParent.signForm(asianParentAverage);
		std::cout << "should have stady medicine, not art." << std::endl;
		std::cout << asianParentAverage;
	}
	catch(std::exception &e)
	{
	std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}