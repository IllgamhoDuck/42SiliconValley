/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 00:10:23 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 02:20:10 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class					Phonebook {

	public:

		Phonebook( void );
		~Phonebook( void );

		void			setFirstName( std::string );
		void			setLastName( std::string );
		void			setNickName( std::string );
		void			setEmailAddress( std::string );
		void			setPhoneNumber( std::string );
		void			setBirthdayDate( std::string );
		void			setFavoriteMeal( std::string );
		void			setUnderwearColor( std::string );
		void			setDarkestSecret( std::string );
		std::string		getFirstName( void ) const;
		std::string		getLastName( void ) const;
		std::string		getNickName( void ) const;
		std::string		getEmailAddress( void ) const;
		std::string		getPhoneNumber( void ) const;
		std::string		getBirthdayDate( void ) const;
		std::string		getFavoriteMeal( void ) const;
		std::string		getUnderwearColor( void ) const;
		std::string		getDarkestSecret( void ) const;

		static int		getNbPhonebook( void );
		void			addNbPhonebook( void );

	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_emailAddress;
		std::string		_phoneNumber;
		std::string		_birthdayDate;
		std::string		_favoriteMeal;
		std::string		_underwearColor;
		std::string		_darkestSecret;

		static int		_nbPhonebook;
};

void					addPhoneBook( Phonebook * phonebook );	
void					searchPhoneBook( Phonebook * phonebook );

#endif
