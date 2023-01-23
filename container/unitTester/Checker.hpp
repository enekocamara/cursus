/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:21:00 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/11 12:33:18 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <stdlib.h>
#include <iostream>
#include "color.h"

class Checker
{
    public:
        Checker();
        ~Checker();
        template <typename T>
        void assertCheck(T expected, T actual)
        {
            if (expected == actual)
                std::cout << GREEN << "\tSUCCESS" << RESET << std::endl;
            else
                std::cout << RED << "ERROR. Test " << std::to_string(_test) << " has failed. Expected: " << expected << " Actual: " << actual << RESET << std::endl;
            _test++;
        }/*
        void assertCheck(bool expected, bool actual);
        void assertCheck(int expected, int actual);
        void assertCheck(unsigned int expected, unsigned int actual);
        void assertCheck(std::string expected, std::string actual);
        void assertCheck(double expected, double actual);*/
    private:
        int _test;

};


#endif