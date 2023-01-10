/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:04:22 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/03 12:16:54 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    std::vector<int> nums1;
    nums1.push_back(-1);
    nums1.push_back(-2);
    nums1.push_back(-3);
    nums1.push_back(-4);
    nums1.push_back(-5);
    std::vector<int> nums2;
    nums2.push_back(-1);
    nums2.push_back(-1);
    std::vector<int> nums3;

    std::cout << easyfind(nums, 3) << std::endl;
    std::cout <<  easyfind(nums1, -7) << std::endl;
    std::cout << easyfind(nums2, -1) << std::endl;
    std::cout << easyfind(nums3, -1) << std::endl;
    return (0);
}