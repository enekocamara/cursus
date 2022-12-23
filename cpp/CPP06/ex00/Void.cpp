/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:41:18 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 12:45:49 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Void.hpp"

Void::Void()
{
   // std::cout << GREEN << "Void default constructor called" << RESET << std::endl;
}

Void::~Void()
{
   // std::cout << RED << "Void default destructor called" << RESET << std::endl;
}

void    Void::fillAllTypes(int value)
{
    _int.setValue(value);
    _double.setValue((double)value);
    _char.setValue((char)value);
    _float.setValue((float)value);
}
void    Void::fillAllTypes(char value)
{
    _int.setValue(value);
    _double.setValue((double)value);
    _char.setValue((char)value);
    _float.setValue((float)value);
}
void    Void::fillAllTypes(double value)
{
    _int.setValue(value);
    _double.setValue((double)value);
    _char.setValue((char)value);
    _float.setValue((float)value);
}
void    Void::fillAllTypes(float value)
{
    _int.setValue(value);
    _double.setValue((double)value);
    _char.setValue((char)value);
    _float.setValue((float)value);
}

int Void::getInt()const
{
    return (_int.getInt());
}

char Void::getChar()const
{
    return (_char.getChar());
}

double Void::getDouble() const
{
    return (_double.getDouble());
}

float Void::getFloat() const
{
    return (_float.getFloat());
}

void Void::checkType(char *str)
{
    size_t len;

    std::string strstring(str);
    len = strlen(str);
    if (len == 0)
       throw Imposible();
   if (len == 1 && str[0] == '\'')
        throw Imposible();
    if (len == 3 && str[0] == '\'' && str[2] == '\'')
    { 
        if (str[1] >= 33 && str[1] <= 126)
            fillAllTypes(str[1]);
        else
            throw NonDisplayable();
    }
    else if (len > 2 && strstring.find('.') <= len)
    {
        if (len > 3 && len == strstring.find('f'))
            fillAllTypes(std::stof(strstring));
        else
            fillAllTypes(std::stod(strstring));
    }
    else if ((atol(str) <= INT_MAX && atol(str) >= INT_MIN) || (len == 1 && str[0] == '0'))
        fillAllTypes(atoi(str));
    else if (atol(str) > INT_MAX)
        throw Overflow();
    else if (atol(str) < (long)INT_MIN)
        throw Underflow();
    else
        throw Imposible();
}

int Void::exceptions(std::string str)
{
    if (str == "+inf" || str == "-inf" || str == "nan")
    {
        _int.assignException(std::string("imposible"));
        _char.assignException(std::string("imposible"));
        _double.assignException(str);
        _float.assignException(str + "f");
        return (1);
    }
    if (str == "+inff" || str == "-inff" || str == "nanf")
    {
        _int.assignException(std::string("imposible"));
        _char.assignException(std::string("imposible"));
        _double.assignException(str.substr(0, str.length() - 1));
        _float.assignException(str);
        return (1);
    }
    return (0);
}

void Void::assign(char *str)
{
    try
    {
        if (!exceptions(std::string(str)))
            checkType(str);
    }
    catch(std::exception &e)
    {
        std::string exception(e.what());
        if (exception == "Underflow" || exception == "Overflow" || exception == "Incorrect number")
            assignException(exception);
    }
}

void Void::assignException(std::string exception)
{
   _int.assignException(exception);
   _char.assignException(exception);
   _double.assignException(exception);
   _float.assignException(exception);
}

void Void::print() const
{
    if (_char.getExceptionTrue())
       std::cout << "char: " << _char.getException() << std::endl;
    else 
        std::cout << "char: " << _char.getChar() << std::endl;
    if (_int.getExceptionTrue())
       std::cout << "int: " << _int.getException() << std::endl;
    else 
        std::cout << "int: " << _int.getInt() << std::endl;
    if (_double.getExceptionTrue())
       std::cout << "double: " << _double.getException() << std::endl;
    else 
    {
        std::cout << "double: " << _double.getDouble() << std::endl;
    }
    if (_float.getExceptionTrue())
       std::cout << "float: " << _float.getException() << std::endl;
    else 
        std::cout << "float: " << _float.getFloat() << std::endl;
}
