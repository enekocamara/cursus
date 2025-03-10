/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:04:58 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/26 13:29:48 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOID_HPP
#define VOID_HPP

#include <iostream>

class Void
{
    public:
        Void(int type, std::string str);
        ~Void();
        
        void printExceptions();
        void setPrecision();
        void printNums();
        void setChar();
    private:
        const int   _type;
        int         _pre;
        double      _num;
        std::string _str;
};

#endif