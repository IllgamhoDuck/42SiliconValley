/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:53:17 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 00:05:03 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}

std::string	const &	Weapon::getType(void)
{
	return this->_type;
}
