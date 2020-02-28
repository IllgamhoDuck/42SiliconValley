/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:42:35 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 02:14:32 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int 			main()
{
	Human human = Human();

	human.action("meleeAttack", "A");
	human.action("rangedAttack", "B");
	human.action("intimidatingShout", "C");
	human.action("skymeleeAttack", "D");
	return 0;
}
