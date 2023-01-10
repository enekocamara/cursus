/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:49:04 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/26 12:19:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int checkNum(char *str)
{
    int i;
    int check;
    int correct;

    correct = 0;
    i = 0;
    check = 1;
    if (str[0] == '-' || str[0] == '+')
        str++;
    while (str[i])
    {
        if (str[i] == '.' && check && i != 0)
        {
            check = 0;
        }
        else if (!isdigit(str[i]) && !(str[i] == 'f' && str[i + 1] == '\0' && !check))
            return (0);
        else
            correct = 2;
        i++;
    }
    return (correct);
}

int checkExceptions(std::string string)
{
    return (string == "nan" || string == "-inf" || string == "+inf" || string == "nanf" || string == "-inff" || string == "+inff");
}

int checkChar(char *str)
{
    size_t len;

    len = strlen(str);
    if (len == 3 && str[0] == '\'' && str[2] == '\'')
    { 
        if (str[1] >= 33 && str[1] <= 126)
            return (3);
    }
    return (0);
}

// 1 = exceptions 2 == num 3 == char They cannot be active at the same time;
