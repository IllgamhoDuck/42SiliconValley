/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:42:52 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 02:32:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

Human::Human(void) {

	return ;
}
Human::~Human(void) {

	return ;
}

void		Human::meleeAttack(std::string const & target)
{
	std::cout << "Attacked " << target << " with pist! It is not effective" << std::endl;
}

void		Human::rangedAttack(std::string const & target)
{
	std::cout << "Attacked " << target << " with gun! It is very powerful" << std::endl;
}

void		Human::intimidatingShout(std::string const & target)
{
	std::cout << "IIII HHHHHATE CCCCCCCPP PISCINE AND " << target << std::endl;
}

void		Human::action(std::string const & action_name, std::string const & target)
{
	typedef void (Human::*memFunc)(std::string const & target);
	 
	memFunc f[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string	actions[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	int			i = -1;

	while (++i < 3)
	{
		if (actions[i].compare(action_name) == 0)
		{
			(this->*(f[i]))(target);
			break ;
		}
		if (i == 2)
			std::cout << "Invalid action : " << action_name << std::endl;

	}
}
