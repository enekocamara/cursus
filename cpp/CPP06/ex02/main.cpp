/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:53:47 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/28 11:24:40 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <math.h>
#include <iostream>

int	random_number(int max)
{
	return (rand() % max);
}

Base * generate(void)
{
    int num = random_number(3);
    std::cout << "Type: " << num << std::endl;
    if (num == 0)
        return (new A());
    if (num == 1)
        return (new B());
    if (num == 2)
        return (new C());
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p) != nullptr)
        std::cout << "A" << std::endl;
    if (dynamic_cast<B *>(p) != nullptr)
        std::cout << "B" << std::endl;
    if (dynamic_cast<C *>(p) != nullptr)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try{
        A hold = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &exception){}
    try{
        B hold = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast &exception){}
    try{
        C hold = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast &exception){}
}

int main()
{
    Base *try1 = generate();
    identify(try1);
    Base *try2 = generate();
    identify(try2);
    Base *try3 = generate();
    identify(try3);
    identify(*try1);
    identify(*try2);
    identify(*try3);
    delete try1;
    delete try2;
    delete try3;
    return (0);
}