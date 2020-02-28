/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:41:13 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:56:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::string randomName[10] = {"GUARRRRR", "GROOOLLL", "HEIEIEIEIEI",
									"HELLOOO", "QUAKRKRKRK", "SOOOOWHAT",
									"HATETHIS", "STUPIDDDDD", "DONTLIKE",
									"WAHTAHPROJECTTTTT"};

	this->_name = randomName[rand() % 10];
	this->_type = "RANDOMMMM";
	return ;
}

Zombie::~Zombie( void )
{
	return ;
}

std::string				Zombie::getName( void )
{
	return this->_name;
}

std::string				Zombie::getType( void )
{
	return this->_type;
}
