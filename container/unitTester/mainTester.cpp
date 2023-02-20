/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:13:37 by ecamara           #+#    #+#             */
/*   Updated: 2023/02/15 13:23:14 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../Namespace.hpp"
#include "../Vector.hpp"

template <class T>
void fillIntGuide(T &vec)
{
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
}

template  <class T, class T2>
void assertVectorContent(Checker &checker, T& origVec, T2& myVec)
{
    for (std::pair<typename T::iterator, typename T2::iterator> i(origVec.begin(), myVec.begin()); i.first != origVec.end()  && i.second != myVec.end(); ++i.first, ++i.second)
    {
        checker.assertCheck(*i.first, *i.second);
    }
}

template  <class T, class T2>
void assertVector(Checker &checker, T& origVec, T2& myVec){
    checker.assertCheck(origVec.size(), myVec.size());
    checker.assertCheck(origVec.capacity(), myVec.capacity());
    assertVectorContent(checker, origVec, myVec);
}

void checkVectorConstructor(Checker &checker)
{
    {
        std::vector<int> origVec;
        ft::Vector<int> myVec;
        checker.assertVectorSize(origVec, myVec);
        checker.assertVectorCapacity(origVec, myVec);
    }
    {
        std::vector<int> origVec(5, 5);
        ft::Vector<int> myVec(5, 5);
        assertVector(checker, origVec, myVec);
        origVec.clear();
        myVec.clear();
        assertVector(checker, origVec, myVec);
    }
    {
        int arr[] = {1, 2, 3, 4, 5};
        int* begin = arr;
        int* end = arr + 5;
        std::vector<int> origVec(begin, end);
        ft::Vector<int> myVec(begin, end);
        assertVector(checker, origVec, myVec);
    }
    {
        std::string name[] = {"Amelia", "watson"};
        std::string* begin = name;
        std::string* end = begin + 2;
        std::vector<std::string> origVec(begin, end);
        ft::Vector<std::string> myVec(begin, end);
        assertVector(checker, origVec, myVec);
    }
    {
        std::vector<int> origVec;
        ft::Vector<int> myVec;

        fillIntGuide(origVec);
        fillIntGuide(myVec);
    }

    
   
    
}

int main()
{
    Checker checker;
    checkVectorConstructor(checker);
    return (0);
}