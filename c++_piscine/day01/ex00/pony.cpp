/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:01:18 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 21:16:16 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "pony.hpp"

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "Ponie " << this->_name << " is born" << std::endl;
	return ;
}

Pony::~Pony( void )
{
	std::cout << "Ponie " << this->_name << " died" << std::endl;
	return ;
}

void			Pony::ponySay( void ) const
{
	std::cout << "My name is " << this->_name << " HEIIEEIEIEI" << std::endl;
	return ;
}
