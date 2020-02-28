/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:26:04 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:58:01 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int N ) : _N(N)
{
	// Create N number of zombie horde
	this->_zombies = new Zombie[this->_N];

	return ;
}

ZombieHorde::~ZombieHorde( void )
{
	int			i = -1;

	while (++i < this->_N)
	{
		std::cout << "<" << this->_zombies[i].getName() << " (";
		std::cout << this->_zombies[i].getType() << ") DEAAAAADDDDDDD...";
		std::cout << std::endl;
	}
	delete [] this->_zombies;

	return ;
}

void			ZombieHorde::announce( void ) 
{
	int			i = -1;

	while (++i < this->_N)
	{
		std::cout << "<" << this->_zombies[i].getName() << " (";
		std::cout << this->_zombies[i].getType() << ") Braiiiiiiinnnssss...";
		std::cout << std::endl;
	}

	return ;
}
