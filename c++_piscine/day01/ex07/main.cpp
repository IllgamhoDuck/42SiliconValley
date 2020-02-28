/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:01:44 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 01:40:04 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int 			main(int ac, char **av)
{
	std::string FILENAME;
	std::string s1;
	std::string s2;

	// Check is parameter number 4
	if (ac != 4)
	{
		std::cout << "usage : replace [FILENAME][string1][string2]" << std::endl;
		return 1;
	}
	FILENAME = av[1];
	s1 = av[2];
	s2 = av[3];

	// Check is parameter has is not empty
	if (FILENAME.length() == 0 || s1.length() == 0 || s2.length() == 0)
	{
		std::cout << "Every parameter should be not be empty" << std::endl;
		return 1;
	}

	// Read the file
	std::ifstream ifs(FILENAME);
	std::string fileContent = "";
	std::string partOfContent;

	while (std::getline(ifs, partOfContent))
	{
		fileContent += partOfContent;
		fileContent += '\n';
	}
	ifs.close();


	// Replace s1 to s2
	size_t pos = fileContent.find(s1);

	while (pos != std::string::npos)
	{
		fileContent.replace(pos, s1.length(), s2);
		pos = fileContent.find(s1, pos + s2.length());
	}

	// Generate the file name
	std::stringstream sstream;

	sstream << FILENAME << ".replace";
	std::string newfile = sstream.str();

	// Write the new content to the file
	std::ofstream ofs(newfile);
	ofs <<  fileContent << std::endl;
	ofs.close();
	return 0;
}
