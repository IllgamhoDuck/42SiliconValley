/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:11:32 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 02:17:04 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

void				addPhoneBook( Phonebook * phonebook ) {

	std::string		input;

	while (1)
	{
		std::cout << "Enter first name : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setFirstName( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter last name : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setLastName( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter nick name : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setNickName( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter email address : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setEmailAddress( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter phone number : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setPhoneNumber( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter birthday date : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setBirthdayDate( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter favorite meal : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setFavoriteMeal( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter underwear color : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setUnderwearColor( input );
		break ;
	}
	while (1)
	{
		std::cout << "Enter darkest secret : ";
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout << "Please enter information" << std::endl;
			continue ;
		}
		phonebook->setDarkestSecret( input );
		break ;
	}
	// Add number of phonebook
	phonebook->addNbPhonebook();
}
