/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:35:17 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/28 10:47:03 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data *data = new Data();
    std::cout << data << std::endl;
    uintptr_t ptr = serialize(data);
    std::cout << ptr << std::endl;
    std::cout << deserialize(ptr) << std::endl;
    return (0);
}