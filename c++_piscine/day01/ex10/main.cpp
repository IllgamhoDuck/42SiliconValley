/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 03:19:16 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 04:07:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sys/stat.h>

void			readFileAndPrint(std::string file)
{
	std::ifstream ifs(file);
	std::string fileContent = "";
	std::string partOfContent;

	while (std::getline(ifs, partOfContent))
	{
		fileContent += partOfContent;
		fileContent += '\n';
	}
	ifs.close();
	std::cout << fileContent;
}

bool			is_dir(char *name)
{
	struct stat st;
	stat(name, &st);
	return S_ISDIR(st.st_mode);
}

void			stdIn(void)
{
	std::string input;

	while (1)
	{
		std::cin >> input;
		std::cout << input << std::endl;
	}
}

int 			main(int ac, char **av)
{
	int			i = 0;

	// Check is it standard input
	if (ac == 1)
		stdIn();
	else
	{
		while (++i < ac)
		{
			// Check it is directory
			if (is_dir(av[i]))
				std::cerr << "cat: " << av[i] << ": Is a directory" << std::endl;

			// Open the file
			std::ifstream ifs(av[i]);
			if (ifs.is_open())
				readFileAndPrint(av[i]);
			else
				std::cerr << "cat: " << av[i] << ": " <<  strerror(errno) << std::endl;
		}
	}
	return 0;
}
