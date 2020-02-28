/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:41:13 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:23:45 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	this->announce();
	return ;
}

Zombie::~Zombie( void )
{
	this->dead();
	return ;
}

void			Zombie::announce( void ) const
{
	std::cout << "<" << this->_name << " (";
	std::cout << this->_type << ") Braiiiiiiinnnssss...";
	std::cout << std::endl;
	return ;
}

void			Zombie::dead( void ) const
{
	std::cout << "<" << this->_name << " (";
	std::cout << this->_type << ") DEAAAAADDDDDDD...";
	std::cout << std::endl;
	return ;
}
