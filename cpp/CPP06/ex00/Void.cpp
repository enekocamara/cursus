/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:06:36 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/26 13:42:50 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Void.hpp"

Void::Void(int type, std::string str): _type(type)
{
    _pre = 1;
    _str = str;
    (void)_type;
}

Void::~Void()
{
    
}

void Void::printExceptions()
{
    std::cout << "Char: Imposible" << std::endl;
    std::cout << "Int: Imposible" << std::endl;
    if (_str == "nan" || _str == "+inf" || _str == "-inf")
    {
        std::cout << "Double: " << _str << std::endl;
        std::cout << "Float: " << _str << "f" << std::endl;
    }
    else
    {
        std::cout << "Double: " << _str.substr(0, _str.length() - 1) << std::endl;
        std::cout << "Float: " << _str << std::endl;
    }
}

void Void::printNums()
{
    if (_num >= 33 && _num <= 126)
        std::cout << "Char: \'" <<  static_cast<char>(_num) << "\'"<< std::endl;
    else
        std::cout << "Char: Non displayable"<< std::endl;
    if (_num > 2147483647)
        std::cout << "Int: Overflow" << std::endl;
    else if(_num < -2147483648)
        std::cout << "Int: Underflow" << std::endl;
    else
        std::cout << "Int: " <<  static_cast<int>(_num) << std::endl;
    std::cout.precision(_pre);
    std::cout << "Float: " << std::fixed << static_cast<float>(_num) << "f" << std::endl;
    std::cout << "Double: " << std::fixed <<  _num << std::endl;
}

void Void::setPrecision()
{
    if (_str.find('.', 0) > _str.size())
        _pre = 1;
    else
    {
        _pre = _str.size() - _str.find('.', 0) - 1;
        if (_str.find('f', 0) <= _str.size())
            _pre--;
    }
    _num = std::stod(_str);
}

void Void::setChar()
{
    std::string num = _str.substr(1, 1);
    _num = static_cast<double>(*num.c_str());
    _pre = 1;
}