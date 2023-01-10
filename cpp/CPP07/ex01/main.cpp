/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:24:16 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/29 10:36:24 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    char *text = new char[20]();
    int i;

    i = 0;
    while (i < 20)
    {
        text[i] = i + 33;
        i++;
    }
    ::iter<char>(text, 20U, ::show<char>);
    ::iter<char>(text, 20U, ::sum<char>);
    std::cout << std::endl;
    ::iter<char>(text, 20U, ::show<char>);
    std::cout << std::endl;
    int *list = new int[20]();
    i = 0;
    while (i < 20)
    {
        list[i] = i;
        i++;
    }
    ::iter<int>(list, 20U, ::show<int>);
    ::iter<int>(list, 20U, ::sum<int>);
    std::cout << std::endl;
    ::iter<int>(list, 20U, ::show<int>);
    
}