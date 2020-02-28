/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:10:59 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 23:35:47 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"
#include "Brain.hpp"

Human::Human( void )
{
	this->_brain = Brain();
	return ;
}

Human::~Human( void )
{
	return ;
}

std::string		Human::identify( void )
{
	return this->_brain.identify();
}

Brain			Human::getBrain( void )
{
	return this->_brain;
}
