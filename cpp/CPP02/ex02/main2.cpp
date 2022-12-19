#include <iostream>
#include "Fixed.hpp" 

int main()
{
	Fixed a;
	Fixed const b( 10 ); Fixed const c( 42.42f ); Fixed const d( b );

	a = b + c;
	std::cout << "[a = " << b << " + " << c << "]" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = c - b;
	std::cout << "[a = " << c << " - " << b << "]" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = b * c;
	std::cout << "[a = " << b << " * " << c << "]" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = b / c;
	std::cout << "[a = " << b << " / " << c << "]" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	a = 0;
    std::cout << "[" << a << "++]" << std::endl;
    std::cout << "a is " << a++ << std::endl;
    std::cout << "a is " << a << std::endl;

	a = 0;
    std::cout << "[++" << a << "]" << std::endl;
	std::cout << "a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;

	a = 0;
	std::cout << "[" << a << "--]" << std::endl;
	std::cout << "a is " << a-- << std::endl;
	std::cout << "a is " << a << std::endl;

	a = 0;
	std::cout << "[--" << a << "]" << std::endl;
	std::cout << "a is " << --a << std::endl;
	std::cout << "a is " << a << std::endl;

	std::cout << "min(" << a << "," <<  b << ")" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	std::cout << "max(" << a << "," <<  b << ")" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}
