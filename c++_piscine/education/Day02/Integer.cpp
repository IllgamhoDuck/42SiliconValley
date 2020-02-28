/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 21:01:07 by hypark            #+#    #+#             */
/*   Updated: 2020/01/15 21:35:47 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Integer.hpp"

Integer::Integer(int const n) : _n(n)
{
	std::cout << "Constructor called with value " << n << std::endl;
	return ;
}

Integer::~Integer(void)
{
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return ;
}

int		Integer::getValue(void) const 
{
	return this->_n;
}

Integer & Integer::operator=(Integer const & rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();

	return *this;
}
		
Integer Integer::operator+(Integer const & rhs) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return Integer(this->_n + rhs.getValue());
}
		
std::ostream & operator<<(std::ostream & o, Integer const & rhs)
{
	o << rhs.getValue();
	return o;
}
