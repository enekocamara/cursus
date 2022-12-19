#include "Bureaucrat.hpp"

class Trial
{
	public:
		Trial(int &a):_a(a)
		{
			//i = new int;
		}
		~Trial()
		{
		//	delete i;
		}
		Trial &operator=(const Trial &trial)
		{
			this->_a = trial._a;
			//this->i = trial.i;
			return (*this);
		}
	private:
		//int *i;
		int &_a;
};

int main()
{
	try
	{
		Bureaucrat bureaucrat("Nice", 1);
		std::cout << bureaucrat << std::endl;
		Bureaucrat emotinalDamage("Can't cook rice", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat emotinalDamage("Can't cook rice n2", 151);
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("Nice", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decreaseGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.increaseGrade();
		Bureaucrat thatGuy(bureaucrat);
		std::cout << thatGuy << std::endl;
		thatGuy.increaseGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}