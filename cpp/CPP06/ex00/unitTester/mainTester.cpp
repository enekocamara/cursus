/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:13:37 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/26 12:19:52 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.hpp"
#include "../header.h"

void testCheckNum(Checker &checker)
{
    checker.assertCheck(1, checkNum((char *)"1"), std::string("1"));
    checker.assertCheck(1, checkNum((char *)"0"), std::string("2"));
    checker.assertCheck(1, checkNum((char *)"-1"), std::string("3"));
    checker.assertCheck(0, checkNum((char *)"'1'"), std::string("4"));
    checker.assertCheck(0, checkNum((char *)"a"), std::string("5"));
    checker.assertCheck(1, checkNum((char *)"1.0"), std::string("6"));
    checker.assertCheck(0, checkNum((char *)"1.1.1"), std::string("7"));
    checker.assertCheck(0, checkNum((char *)"1f"), std::string("8"));
    checker.assertCheck(1, checkNum((char *)"1.1f"), std::string("9"));
    checker.assertCheck(0, checkNum((char *)"-.1"), std::string("10"));
    checker.assertCheck(0, checkNum((char *)""), std::string("11"));
    checker.assertCheck(0, checkNum((char *)"--1"), std::string("12"));
    checker.assertCheck(0, checkNum((char *)"++1"), std::string("13"));
    checker.assertCheck(0, checkNum((char *)"-+1"), std::string("14"));
    checker.assertCheck(0, checkNum((char *)"-f"), std::string("15"));
    checker.assertCheck(0, checkNum((char *)".f"), std::string("16"));
    checker.assertCheck(0, checkNum((char *)"1.0ff"), std::string("17"));
    checker.assertCheck(1, checkNum((char *)"10000000000000000000000000"), std::string("18"));
    checker.assertCheck(1, checkNum((char *)"-1000000000000000000000000"), std::string("19"));
    checker.assertCheck(1, checkNum((char *)"+1"), std::string("20"));
    checker.assertCheck(1, checkNum((char *)"+24"), std::string("21"));
    checker.assertCheck(0, checkNum((char *)"@$%^&"), std::string("22"));
}

void testCheckExceptions(Checker &checker)
{
    checker.assertCheck(1, checkExceptions(std::string("nan")), std::string("23"));
    checker.assertCheck(1, checkExceptions(std::string("+inf")), std::string("24"));
    checker.assertCheck(1, checkExceptions(std::string("-inf")), std::string("25"));
    checker.assertCheck(1, checkExceptions(std::string("nanf")), std::string("26"));
    checker.assertCheck(1, checkExceptions(std::string("-inff")), std::string("27"));
    checker.assertCheck(1, checkExceptions(std::string("+inff")), std::string("28"));
    checker.assertCheck(0, checkExceptions(std::string("-nan")), std::string("29"));
    checker.assertCheck(0, checkExceptions(std::string("+nan")), std::string("30"));
    checker.assertCheck(0, checkExceptions(std::string("++inf")), std::string("31"));
    checker.assertCheck(0, checkExceptions(std::string("--inf")), std::string("32"));
    checker.assertCheck(0, checkExceptions(std::string("nanfff")), std::string("33"));
    checker.assertCheck(0, checkExceptions(std::string("-infff")), std::string("34"));
    checker.assertCheck(0, checkExceptions(std::string("+-inff")), std::string("35"));
    checker.assertCheck(0, checkExceptions(std::string("")), std::string("36"));
}

void testCheckChar(Checker &checker)
{
    checker.assertCheck(1, checkChar((char *)"'a'"), std::string("37"));
    checker.assertCheck(1, checkChar((char *)"'A'"), std::string("38"));
    checker.assertCheck(1, checkChar((char *)"'z'"), std::string("39"));
    checker.assertCheck(1, checkChar((char *)"'Z'"), std::string("40"));
    checker.assertCheck(0, checkChar((char *)"'#$'"), std::string("41"));
    checker.assertCheck(0, checkChar((char *)"'+gp4'"), std::string("42"));
    checker.assertCheck(1, checkChar((char *)"'%'"), std::string("43"));
    checker.assertCheck(1, checkChar((char *)"'\''"), std::string("44"));
    checker.assertCheck(1, checkChar((char *)"'1'"), std::string("45"));
    checker.assertCheck(1, checkChar((char *)"'0'"), std::string("46"));
    checker.assertCheck(0, checkChar((char *)"'\t'"), std::string("47"));
    checker.assertCheck(0, checkChar((char *)"'\n'"), std::string("48"));
    checker.assertCheck(0, checkChar((char *)"'\0'"), std::string("49"));
}


int main()
{
    Checker checker;
    testCheckNum(checker);
    testCheckExceptions(checker);
    testCheckChar(checker);
    return (0);
}