/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:59:01 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 22:58:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"

int			main( void )
{
	ZombieHorde zombieHorde(10);
	zombieHorde.announce();
	//system("leaks zombie");
	return 0;
};
