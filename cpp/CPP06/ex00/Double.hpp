/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:21:47 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 12:33:02 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <iostream>
#include <string>
#include "color.h"

class Double
{
    public:
        Double();
        ~Double();
        void setValue(double value);
        void assignException(std::string exception);
        double getDouble()const;
        int getExceptionTrue()const;
        std::string getException()const;
    private:
        double _value;
        int _exceptionTrue;
        std::string _exception;
};

#endif