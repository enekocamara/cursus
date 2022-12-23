/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:21:47 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 12:34:04 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_HPP
#define INT_HPP

#include <iostream>
#include <string>
#include "color.h"

class Int
{
    public:
        Int();
        ~Int();
        void setValue(int value);
        int getInt()const;
        void assignException(std::string exception);
        int getExceptionTrue()const;
        std::string getException()const;
    private:
        int _value;
        int _exceptionTrue;
        std::string _exception;
};

#endif