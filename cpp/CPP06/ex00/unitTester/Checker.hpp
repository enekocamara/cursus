/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:21:00 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/26 11:11:42 by ecamara          ###   ########.fr       */
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
        void assertCheck(int expected, int actual, std::string test) const;
        void assertCheck(std::string expected, std::string actual, std::string test) const;
        void assertCheck(double expected, double actual, std::string test) const;
};

#endif