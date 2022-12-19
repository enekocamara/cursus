/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:14:55 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/05 11:04:20 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string ft_replace(std::string text, std::string str1, std::string str2)
{
	std::string text2;
	std::size_t found;
	std::string temp;
	int	index;

	found = 0;
	index = 0;
	if (text.find(str1) + str1.length() == text.length())
		return (text);
	do
	{
		found = text.find(str1);
		if (found > text.length())
		{
			temp = text.substr(0, text.length());
			text2 += temp;
			break ;
		}
		temp = text.substr(0, found);
		text.erase(0, found);
		text2 += temp;
		text.erase(0, str1.length());
		text2 += str2;
		temp.clear();
	}	
	while (1);
	return (text2);
}

int main(int argc, char **argv)
{
	std::ifstream	file1;
	std::ofstream	file2;
	std::string temp;
	std::string	text;
	std::string text2;

	if (argc != 4)
		return (1);
	std::string textName(argv[1]);
	file1.open(textName, std::ios::in);
	while (!file1.eof())
	{
		std::getline(file1, temp, '\n');
		text += temp;
		if (!file1.eof())
			text += "\n";
		temp.clear();
	}
	std::string str1(argv[2]);
	std::string str2(argv[3]);
	text2 = ft_replace(text, argv[2], argv[3]);
	file1.close();
	textName += ".replace";
	file2.open(textName);
	file2 << text2;
	file2.close();
	return 0;
}