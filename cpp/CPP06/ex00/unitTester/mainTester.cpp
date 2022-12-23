/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:10:12 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 12:22:56 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "Checker.hpp"

void testInt(Void voidTest, Checker const &checker, int value, std::string test)
{
    voidTest.fillAllTypes(value);
    checker.assertCheck(value, voidTest.getInt(), test);
}

void testCheckTypeInt(Void voidTest, Checker const &checker, char *value, char *expected, std::string test)
{
    try
    {
        voidTest.checkType(value);
        checker.assertCheck(atoi(value), voidTest.getInt(), test);
    }
    catch(const std::exception& e)
    {
        if (e.what() == std::string("stod: no conversion"))
            checker.assertCheck(std::string(expected), std::string("Imposible"), test);
        else
            checker.assertCheck(std::string(expected), std::string(e.what()), test);
    }
}

void testCheckTypeChar(Void voidTest, Checker const &checker, char *value, char *expected, std::string test)
{
    try
    {
        voidTest.checkType(value);
        std::string exception(expected);
        if (exception == "Underflow" || exception == "Overflow" || exception == "Incorrect number" || exception == "Non displayable")
            std::cout << RED << "ERROR. Test " << test << " has failed. Expected: " << expected << " Actual: " << voidTest.getChar() << RESET << std::endl;
        else
            checker.assertCheck(expected[0], voidTest.getChar(), test);
    }
    catch(const std::exception& e)
    {
        if (e.what() == std::string("stod: no conversion"))
            checker.assertCheck(std::string(expected), std::string("Imposible"), test);
        else
            checker.assertCheck(std::string(expected), std::string(e.what()), test);
    }
}

void testCheckTypeDouble(Void voidTest, Checker const &checker, char *value, char *expected, std::string test)
{
    try
    {
        voidTest.checkType(value);
        std::string exception(expected);
        if (exception == "Underflow" || exception == "Overflow" || exception == "Incorrect number" || exception == "Non displayable")
            std::cout << RED << "ERROR. Test " << test << " has failed. Expected: " << expected << " Actual: " << voidTest.getDouble() << RESET << std::endl;
        else
            checker.assertCheck(std::stod(value), voidTest.getDouble(), test);
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        if (e.what() == std::string("stod: no conversion"))
            checker.assertCheck(std::string(expected), std::string("Imposible"), test);
        else
            checker.assertCheck(std::string(expected), std::string(e.what()), test);
    }
}

void testCheckTypeFloat(Void voidTest, Checker const &checker, char *value, char *expected, std::string test)
{
    try
    {
        voidTest.checkType(value);
        std::string exception(expected);
        if (exception == "Underflow" || exception == "Overflow" || exception == "Incorrect number" || exception == "Non displayable")
            std::cout << RED << "ERROR. Test " << test << " has failed. Expected: " << expected << " Actual: " << voidTest.getDouble() << RESET << std::endl;
        else
            checker.assertCheck(std::stof(value), voidTest.getFloat(), test);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        if (e.what() == std::string("stof: no conversion"))
            checker.assertCheck(std::string(expected), std::string("Imposible"), test);
        else
            checker.assertCheck(std::string(expected), std::string(e.what()), test);
    }
}

void testExceptions(Void voidTest, Checker const &checker, char *value, int expected, std::string test)
{
    checker.assertCheck(expected, voidTest.exceptions(std::string(value)), test);
}

void checkInt(Void voidTest, Checker const &checker)
{
    /* FILL ALL TYPES CHECKER */

    //TEST 1
    testInt(voidTest, checker, 1, std::string("1"));
    //TEST 2
    testInt(voidTest, checker, 0, std::string("2"));
    //TEST 3
    testInt(voidTest, checker, -1, std::string("3"));
    //TEST 4
    testInt(voidTest, checker, 17, std::string("4"));
    //TEST 5
    testInt(voidTest, checker, -17, std::string("5"));
    //TEST 6
    testInt(voidTest, checker, 2147483647, std::string("6"));
    //TEST 7
    testInt(voidTest, checker, -2147483646, std::string("7 "));
}

void checkType(Void voidTest, Checker const &checker)
{
    /* INT CHECKS*/
    //TEST 8
    testCheckTypeInt(voidTest, checker, (char *)"1", (char *)"1",std::string("8"));
    //TEST 9
    testCheckTypeInt(voidTest, checker, (char *)"0", (char *)"0",std::string("9"));
    //TEST 10
    testCheckTypeInt(voidTest, checker, (char *)"-1", (char *)"-1",std::string("10"));
    //TEST 11
    testCheckTypeInt(voidTest, checker, (char *)"17", (char *)"17",std::string("11"));
    //TEST 12
    testCheckTypeInt(voidTest, checker, (char *)"-17", (char *)"-17",std::string("12"));
    //TEST 13
    testCheckTypeInt(voidTest, checker, (char *)"2147483647", (char *)"2147483647",std::string("13"));
    //TEST 14
    testCheckTypeInt(voidTest, checker, (char *)"-2147483646", (char *)"-2147483646",std::string("14"));
    //TEST 15
    testCheckTypeInt(voidTest, checker, (char *)"2147483648", (char *)"Overflow",std::string("15"));
    //TEST 16
    testCheckTypeInt(voidTest, checker, (char *)"-2147483647", (char *)"Underflow",std::string("16"));
    //TEST 17
    testCheckTypeInt(voidTest, checker, (char *)"-999999999999999999999", (char *)"Underflow",std::string("17"));
    //TEST 18
    testCheckTypeInt(voidTest, checker, (char *)"999999999999999999999", (char *)"Overflow",std::string("18"));

    /* IMPOSIBLE */
    //TEST 19
    testCheckTypeInt(voidTest, checker, (char *)"hola", (char *)"Imposible",std::string("19"));
    //TEST 20
    testCheckTypeInt(voidTest, checker, (char *)"hola.", (char *)"Imposible",std::string("20"));
    //TEST 21
    testCheckTypeInt(voidTest, checker, (char *)"hola.f", (char *)"Imposible",std::string("21"));
    //TEST 22
    testCheckTypeInt(voidTest, checker, (char *)"1.", (char *)"Imposible",std::string("22"));
    //TEST 23
    testCheckTypeInt(voidTest, checker, (char *)".1", (char *)"Imposible",std::string("23"));
    //TEST 24
    testCheckTypeInt(voidTest, checker, (char *)".", (char *)"Imposible",std::string("24"));
    //TEST 25
    testCheckTypeInt(voidTest, checker, (char *)"..", (char *)"Imposible",std::string("25"));
    //TEST 26
    testCheckTypeInt(voidTest, checker, (char *)"1..", (char *)"Imposible",std::string("26"));
    //TEST 27
    testCheckTypeInt(voidTest, checker, (char *)"..1", (char *)"Imposible",std::string("27"));
    //TEST 28
    testCheckTypeInt(voidTest, checker, (char *)".1.", (char *)"Imposible",std::string("28"));
    //TEST 29
    testCheckTypeInt(voidTest, checker, (char *)",1,", (char *)"Imposible",std::string("29"));
    //TEST 30
    testCheckTypeInt(voidTest, checker, (char *)"", (char *)"Imposible",std::string("30"));

    /* CHECK CHAR */
    //TEST 31
    testCheckTypeChar(voidTest, checker, (char *)"\'*\'", (char *)"*",std::string("31"));
    //TEST 32
    testCheckTypeChar(voidTest, checker, (char *)"\'a\'", (char *)"a",std::string("32"));
    //TEST 33
    testCheckTypeChar(voidTest, checker, (char *)"\'z\'", (char *)"z",std::string("33"));
    //TEST 34
    testCheckTypeChar(voidTest, checker, (char *)"\'{\'", (char *)"{",std::string("33"));
    //TEST 35
    testCheckTypeChar(voidTest, checker, (char *)"\'0\'", (char *)"0",std::string("34"));
    //TEST 36
    testCheckTypeChar(voidTest, checker, (char *)"\'\n\'", (char *)"Non displayable",std::string("35"));
    //TEST 37
    testCheckTypeChar(voidTest, checker, (char *)"\'\t\'", (char *)"Non displayable",std::string("36"));
    //TEST 38
    testCheckTypeChar(voidTest, checker, (char *)"\'\0\'", (char *)"Imposible",std::string("37"));

    /* CHECK DOUBLE*/
     //TEST 39
    testCheckTypeDouble(voidTest, checker, (char *)"1.0", (char *)"1.0",std::string("39"));
    //TEST 40
    testCheckTypeDouble(voidTest, checker, (char *)"0.0", (char *)"0.0",std::string("40"));
    //TEST 41
    testCheckTypeDouble(voidTest, checker, (char *)"-1.0", (char *)"-1.0",std::string("41"));
    //TEST 42
    testCheckTypeDouble(voidTest, checker, (char *)"17.0", (char *)"17.0",std::string("42"));
    //TEST 43
    testCheckTypeDouble(voidTest, checker, (char *)"-17.0", (char *)"-17.0",std::string("43"));
    //TEST 44
    testCheckTypeDouble(voidTest, checker, (char *)"2147483647.0", (char *)"2147483647.0",std::string("44"));
    //TEST 45
    testCheckTypeDouble(voidTest, checker, (char *)"-2147483646.0", (char *)"-2147483646.0",std::string("45"));
    //TEST 46
    testCheckTypeDouble(voidTest, checker, (char *)"2147483648.0", (char *)"2.14748e+09",std::string("46"));
    //TEST 47
    testCheckTypeDouble(voidTest, checker, (char *)"-2147483647.0", (char *)"-2.14748e+09",std::string("47"));
    //TEST 48
    testCheckTypeDouble(voidTest, checker, (char *)"-999999999999999999999.0", (char *)"-1e+21",std::string("48"));
    //TEST 49
    testCheckTypeDouble(voidTest, checker, (char *)"999999999999999999999.0", (char *)"1e+21",std::string("49"));
    //TEST 48
    testCheckTypeDouble(voidTest, checker, (char *)"-0.0012111", (char *)"-0.0012111",std::string("48"));
    //TEST 49
    testCheckTypeDouble(voidTest, checker, (char *)"0.000001", (char *)"0.000001",std::string("49"));

    /* CHECK FLOAT*/
    //TEST 50
    testCheckTypeFloat(voidTest, checker, (char *)"1.0f", (char *)"1.0f",std::string("50"));
    //TEST 51
    testCheckTypeFloat(voidTest, checker, (char *)"0.0f", (char *)"0.0f",std::string("51"));
    //TEST 52
    testCheckTypeFloat(voidTest, checker, (char *)"-1.0f", (char *)"-1.0f",std::string("52"));
    //TEST 53
    testCheckTypeFloat(voidTest, checker, (char *)"17.0f", (char *)"17.0f",std::string("53"));
    //TEST 54
    testCheckTypeFloat(voidTest, checker, (char *)"-17.0f", (char *)"-17.0f",std::string("54"));
    //TEST 55
    testCheckTypeFloat(voidTest, checker, (char *)"2147483647.0f", (char *)"2147483647.0f",std::string("55"));
    //TEST 56
    testCheckTypeFloat(voidTest, checker, (char *)"-2147483646.0f", (char *)"-2147483646.0f",std::string("56"));
    //TEST 57
    testCheckTypeFloat(voidTest, checker, (char *)"2147483648.0f", (char *)"2.14748e+09f",std::string("57"));
    //TEST 58
    testCheckTypeFloat(voidTest, checker, (char *)"-2147483647.0f", (char *)"-2.14748e+09f",std::string("58"));
    //TEST 59
    testCheckTypeFloat(voidTest, checker, (char *)"-999999999999999999999.0f", (char *)"-1e+21f",std::string("59"));
    //TEST 60
    testCheckTypeFloat(voidTest, checker, (char *)"999999999999999999999.0f", (char *)"1e+21f",std::string("60"));
    //TEST 61
    testCheckTypeFloat(voidTest, checker, (char *)"-0.0012111f", (char *)"-0.0012111f",std::string("61"));
    //TEST 62
    testCheckTypeFloat(voidTest, checker, (char *)"0.000001f", (char *)"0.000001f",std::string("62"));
}

void checkExceptions(Void voidTest, Checker const &checker)
{
    /* EXCEPTIONS CHECKS*/
    //TEST 63
    testExceptions(voidTest, checker, (char *)"nan", 1, std::string("63"));
    //TEST 64
    testExceptions(voidTest, checker, (char *)"nanf", 1, std::string("64"));
    //TEST 65
    testExceptions(voidTest, checker, (char *)"+inf", 1, std::string("65"));
    //TEST 66
    testExceptions(voidTest, checker, (char *)"+inff", 1, std::string("66"));
    //TEST 67
    testExceptions(voidTest, checker, (char *)"-inf", 1, std::string("67"));
    //TEST 68
    testExceptions(voidTest, checker, (char *)"-inff", 1, std::string("68"));
    //TEST 69
    testExceptions(voidTest, checker, (char *)"-nanf", 0, std::string("69"));
    //TEST 70
    testExceptions(voidTest, checker, (char *)"+nanf", 0, std::string("70"));
    //TEST 71
    testExceptions(voidTest, checker, (char *)"-infff", 0, std::string("71"));
    //TEST 72
    testExceptions(voidTest, checker, (char *)"", 0, std::string("72"));
}

void TestCheckTypes(Checker const &checker)
{
    Void voidTest;

    checkInt(voidTest, checker);
    checkType(voidTest, checker);
    checkExceptions(voidTest, checker);
}

int main(void)
{
    Checker checker;
    TestCheckTypes(checker);
    return (0);
}
