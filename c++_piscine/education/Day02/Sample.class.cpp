/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:22:00 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 20:47:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Deconstructor called" << std::endl;
	return ;
}

void		Sample::bar(char const c) const
{
	std::cout << "Member function bar called with char overload : " << c << std::endl;
	return ;
}

void		Sample::bar(int const n) const
{
	std::cout << "Member function bar called with int overload : " << n << std::endl;
	return ;
}

void		Sample::bar(float const z) const
{
	std::cout << "Member function bar called with float overload : " << z << std::endl;
	return ;
}

void		Sample::bar(Sample const & i) const
{
	(void) i;
	std::cout << "Member function bar called with Sample overload " << std::endl;
	return ;
}
