/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:13:37 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/11 13:08:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../Namespace.hpp"

template <class T>
void fillIntGuide(T &vec)
{
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
}

void checkVectorConstructor(Checker &checker)
{
    {
        std::vector<int> originalInt;
        ft::Vector<int> myInt;
        checker.assertCheck(originalInt.size(), myInt.size());
        checker.assertCheck(originalInt.capacity(), myInt.capacity());
    }
    {
        std::vector<int> originalInt(5, 5);
        ft::Vector<int> myInt(5, 5);
        checker.assertCheck(originalInt.size(), myInt.size());
        checker.assertCheck(originalInt.capacity(), myInt.capacity());
    }
    

    /*
    std::vector<int> originalIntGuide;
    Vector<int> myIntGuide;

    fillIntGuide(originalIntGuide);
    fillIntGuide(myIntGuide);
    */
}

int main()
{
    Checker checker;
    checkVectorConstructor(checker);
    return (0);
}