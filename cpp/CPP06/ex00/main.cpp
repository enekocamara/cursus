/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:47:15 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/26 13:41:29 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (0);
    
    int type = checkChar(argv[1]) + checkNum(argv[1]) + checkExceptions(std::string(argv[1])); // 1 == exceptions; 2 == num; 3 == char;
    if (!type || type > 3)
    {
        std::cerr << RED << "invalid input, type == " << type << RESET << std::endl;
        return (1);
    }
    Void input(type, std::string(argv[1]));
    if (type == 1)
        input.printExceptions();
    if (type == 2)
        input.setPrecision();
    if (type == 3)
        input.setChar();
    if (type == 2 || type == 3)
        input.printNums();
    return (0);
}