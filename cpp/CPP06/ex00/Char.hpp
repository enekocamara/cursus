/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:21:47 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/22 18:32:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_HPP
#define CHAR_HPP

#include <iostream>
#include <string>
#include "color.h"

class Char
{
    public:
        Char();
        ~Char();
        void setValue(char value);
        void assignException(std::string &exception);
        char getChar()const;
    private:
        char _value;
        int _exceptionTrue;
        std::string _exception;
};

#endif