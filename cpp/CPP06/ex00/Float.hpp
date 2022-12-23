/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:21:47 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 12:33:21 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <iostream>
#include <string>
#include "color.h"

class Float
{
    public:
        Float();
        ~Float();
        void setValue(float value);
        void assignException(std::string exception);
        float getFloat()const;
        int getExceptionTrue()const;
        std::string getException()const;
    private:
        float _value;
        int _exceptionTrue;
        std::string _exception;
};

#endif