/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:07:22 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 00:49:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void			HumanB::attack(void)
{
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon->getType() << std::endl;
	return ;
}

void			HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
