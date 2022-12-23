/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:25:24 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 11:32:59 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.hpp"

Checker::Checker()
{
    std::cout << GREEN << "Checker standar constructor called" << RESET << std::endl;
}

Checker::~Checker()
{
    std::cout << RED << "Checker standar destructor called" << RESET << std::endl;
}

void Checker::assertCheck(int expected, int actual, std::string test) const
{
    if (expected == actual)
        std::cout << GREEN << "SUCCESS" << RESET << std::endl;
    else
        std::cout << RED << "ERROR. Test " << test << " has failed. Expected: " << expected << " Actual: " << actual << RESET << std::endl;
}

void Checker::assertCheck(std::string expected, std::string actual, std::string test) const
{
    if (expected == actual)
        std::cout << GREEN << "SUCCESS" << RESET << std::endl;
    else
        std::cout << RED << "ERROR. Test " << test << " has failed. Expected: " << expected << " Actual: " << actual << RESET << std::endl;
}

void Checker::assertCheck(double expected, double actual, std::string test) const
{
    if (expected == actual)
        std::cout << GREEN << "SUCCESS" << RESET << std::endl;
    else
        std::cout << RED << "ERROR. Test " << test << " has failed. Expected: " << expected << " Actual: " << actual << RESET << std::endl;
}