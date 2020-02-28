/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 00:17:11 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 02:20:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

int				main(void ) {

	std::string		command;
	Phonebook		phonebook[8];

	while (1)
	{
		//system("clear");
		// Get command
		std::cout << "PHONE BOOK" << std::endl;
		std::cout << "==========" << std::endl;
		std::cout << "ADD" << std::endl;
		std::cout << "SEARCH" << std::endl;
		std::cout << "EXIT" << std::endl;
		std::getline(std::cin, command);

		// Process command
		if (command == "ADD")
		{
			if (Phonebook::getNbPhonebook() == 8)
				std::cout << "Phonebook is full of 8 contact" << std::endl;
			else
				addPhoneBook(phonebook + Phonebook::getNbPhonebook());
		}
		else if (command == "SEARCH")
			searchPhoneBook(phonebook);
		else if (command == "EXIT")
		{
			std::cout << "EXIT command accepted" << std::endl;
			break ;
		}
		else
			std::cout << "Please enter valid command" << std::endl;
	}

	return 0;
}
