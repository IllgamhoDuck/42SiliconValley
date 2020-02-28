/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonical.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 21:51:39 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 22:11:23 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "canonical.hpp"

Sample::Sample(void) : _foo(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Sample::Sample(int const n) : _foo(n)
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

Sample::Sample(Sample const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Sample & Sample::operator=(Sample const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &rhs)
		this->_foo = rhs.getFoo();
	return *this;
}

int		Sample::getFoo(void) const
{
	return this->_foo;
}

std::ostream & 		operator<<(std::ostream & o, Sample const & i)
{
	std::cout << "The value of _foo is : ";
	o << i.getFoo();
	return o;
}
