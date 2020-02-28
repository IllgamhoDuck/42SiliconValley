/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:00:10 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 02:59:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

void				display( std::string string, int last) {

	if (string.length() > 10)
		std::cout << std::setw(9) << string.substr(0, 9) << '.';
	else
	{
		std::cout.setf(std::ios::right);
		std::cout << std::setw(10) << std::setfill(' ') << string;
	}
	if (last == 1)
		std::cout << '|';
}

void				display_full( std::string string, int last) {

	std::cout << string;
	if (last == 1)
		std::cout << std::endl;
}

void				searchPhoneBook( Phonebook * phonebook ) {

	int				i = -1;
	int				index;

	display("index", 1);
	display("first name", 1);
	display("last name", 1);
	display("nick name", 0);
	std::cout << std::endl;
	while (++i < Phonebook::getNbPhonebook())
	{
		display(std::to_string(i), 1);
		display(phonebook[i].getFirstName(), 1);
		display(phonebook[i].getLastName(), 1);
		display(phonebook[i].getNickName(), 0);
		std::cout << std::endl;
	}

	// If there is at least one phonebook
	if (i > 0)
	{
		while (1)
		{
			std::cout << "Choose the index you want to look at" << std::endl;
			std::cin >> index;
			if (index >= 0 && index < Phonebook::getNbPhonebook())
			{
				display_full("first name : ", 0);
				display_full(phonebook[index].getFirstName(), 1);
				display_full("last name : ", 0);
				display_full(phonebook[index].getLastName(), 1);
				display_full("nick name : ", 0);
				display_full(phonebook[index].getNickName(), 1);
				display_full("email address : ", 0);
				display_full(phonebook[index].getEmailAddress(), 1);
				display_full("phone number : ", 0);
				display_full(phonebook[index].getPhoneNumber(), 1);
				display_full("birthday date ; ", 0);
				display_full(phonebook[index].getBirthdayDate(), 1);
				display_full("favorite meal : ", 0);
				display_full(phonebook[index].getFavoriteMeal(), 1);
				display_full("underwear color : ", 0);
				display_full(phonebook[index].getUnderwearColor(), 1);
				display_full("Darkest secret : ", 0);
				display_full(phonebook[index].getDarkestSecret(), 1);
				break ;
			}
			else
				std::cout << "Invalid index!" << std::endl;
		}
	}
}
