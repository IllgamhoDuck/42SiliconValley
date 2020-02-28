/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:01:49 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 21:20:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "pony.hpp"

void		ponyOnTheHeap(std::string name)
{
	Pony*	pony = new Pony(name);

	pony->ponySay();
	delete pony;

	return ;
}

void 		ponyOnTheStack(std::string name)
{
	Pony	pony = Pony(name);

	pony.ponySay();
	return ;
}

int			main( void )
{
	ponyOnTheStack("asdf");
	ponyOnTheHeap("qwer");

	return 0;
};
