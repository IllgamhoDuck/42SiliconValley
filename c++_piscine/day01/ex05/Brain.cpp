/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:17:40 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 23:49:07 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain( void )
{
	this->_brainAddress = this;
	return ;
}

Brain::~Brain( void )
{
	return ;
}

std::string			Brain::identify( void )
{
	std::stringstream sstream;

	sstream << std::hex << this->_brainAddress;
	return sstream.str();
}
