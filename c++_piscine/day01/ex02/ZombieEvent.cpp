/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:41:52 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:23:10 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void )
{
	// set default zombie type
	this->_type = "GUAOHHHHH";
	return ;
}

ZombieEvent::~ZombieEvent( void )
{
	return ;
}

void			ZombieEvent::setZombieType( std::string type )
{
	this->_type = type;
	return ;
}

Zombie*			ZombieEvent::newZombie( std::string name )
{
	Zombie		*zombie = new Zombie(name, this->_type);
	return zombie;
}
