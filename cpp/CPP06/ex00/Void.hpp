/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:01:00 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/23 12:46:46 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOID_HPP
#define VOID_HPP

#include "Double.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Char.hpp"
#include "color.h"
#include <iostream>
<iomanip>

class Void
{
    public:
        Void();
        ~Void();

        void assign(char *str);
        void assignException(std::string exception);
        void checkType(char *str);
        void fillAllTypes(int value);
        void fillAllTypes(char c);
        void fillAllTypes(double value);
        void fillAllTypes(float value);
        int getInt()const;
        char getChar()const;
        double getDouble()const;
        float getFloat()const;
        int exceptions(std::string str);
        void print()const;
        class Overflow : public std::exception
		{
			virtual const char* what() const throw(){
                return ("Overflow");
            }
		};
        class Imposible : public std::exception
		{
			virtual const char* what() const throw(){
                 return ("Imposible");
            }
		};
        class Underflow : public std::exception
		{
			virtual const char* what() const throw(){
                return ("Underflow");
            }
		};
        class IncorrectNumber : public std::exception
		{
			virtual const char* what() const throw(){
                return ("Incorrect number");
            }
		};
        class NonDisplayable : public std::exception
		{
			virtual const char* what() const throw(){
                return ("Non displayable");
            }
		};
    private:
        Int _int;
        Float _float;
        Double _double;
        Char _char;
};

#endif