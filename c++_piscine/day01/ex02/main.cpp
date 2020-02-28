/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:59:01 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:20:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void		randomChump( void )
{
	std::string randomName[10] = {"GUARRRRR", "GROOOLLL", "HEIEIEIEIEI",
									"HELLOOO", "QUAKRKRKRK", "SOOOOWHAT",
									"HATETHIS", "STUPIDDDDD", "DONTLIKE",
									"WAHTAHPROJECTTTTT"};

	Zombie zombie = Zombie(randomName[rand() % 10], "NOOOOOOO");
	return ;
}

int			main( void )
{
	ZombieEvent zombieEvent;

	// Before assigning a type
	Zombie*	zombie1 = zombieEvent.newZombie("zombie");

	// After assigning a type
	zombieEvent.setZombieType("DUCK");
	Zombie*	zombie2 = zombieEvent.newZombie("zombie");

	// random zombies
	randomChump();
	randomChump();

	delete zombie1;
	delete zombie2;
	return 0;
};
