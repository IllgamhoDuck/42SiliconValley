/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:59:36 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 01:51:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

// Constructor
Phonebook::Phonebook( void ) {
	
	return ;
}

// Deconstructor
Phonebook::~Phonebook( void ) {
	
	Phonebook::_nbPhonebook -= 1;
	return ;
}

int				Phonebook::getNbPhonebook( void ) {

	return Phonebook::_nbPhonebook;
}

void			Phonebook::addNbPhonebook( void ) {

	Phonebook::_nbPhonebook += 1;
	return ;
}

int				Phonebook::_nbPhonebook = 0;

void			Phonebook::setFirstName( std::string firstName ) {

	this->_firstName = firstName;
	return ;
}

void			Phonebook::setLastName( std::string lastName ) {

	this->_lastName = lastName;
	return ;
}

void			Phonebook::setNickName( std::string nickName ) {

	this->_nickName = nickName;
	return ;
}

void			Phonebook::setEmailAddress( std::string emailAddress ) {

	this->_emailAddress = emailAddress;
	return ;
}

void			Phonebook::setPhoneNumber( std::string phoneNumber ) {

	this->_phoneNumber = phoneNumber;
	return ;
}

void			Phonebook::setBirthdayDate( std::string birthdayDate ) {

	this->_birthdayDate = birthdayDate;
	return ;
}

void			Phonebook::setFavoriteMeal( std::string favoriteMeal ) {

	this->_favoriteMeal = favoriteMeal;
	return ;
}

void			Phonebook::setUnderwearColor( std::string underwearColor ) {

	this->_underwearColor = underwearColor;
	return ;
}

void			Phonebook::setDarkestSecret( std::string darkestSecret ) {

	this->_darkestSecret = darkestSecret;
	return ;
}

std::string		Phonebook::getFirstName( void ) const {

	return this->_firstName;
}

std::string		Phonebook::getLastName( void ) const {

	return this->_lastName;
}

std::string		Phonebook::getNickName( void ) const {

	return this->_nickName;
}

std::string		Phonebook::getEmailAddress( void ) const {

	return this->_emailAddress;
}

std::string		Phonebook::getPhoneNumber( void ) const {

	return this->_phoneNumber;
}

std::string		Phonebook::getBirthdayDate( void ) const {

	return this->_birthdayDate;
}

std::string		Phonebook::getFavoriteMeal( void ) const {

	return this->_favoriteMeal;
}

std::string		Phonebook::getUnderwearColor( void ) const {

	return this->_underwearColor;
}

std::string		Phonebook::getDarkestSecret( void ) const {

	return this->_darkestSecret;
}

