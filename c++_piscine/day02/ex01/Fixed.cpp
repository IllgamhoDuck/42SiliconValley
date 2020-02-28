/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:05:35 by hypark            #+#    #+#             */
/*   Updated: 2020/01/16 00:38:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const n) : _fixedPoint(n << Fixed::_bits)
{
	std::cout << "Int Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const z) : _fixedPoint(std::roundf(z * (1 << Fixed::_bits)))
{
	std::cout << "Float Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	return this->_fixedPoint;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
	return ;
}
float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint)/(1 << Fixed::_bits);
}

int		Fixed::toInt(void) const
{
	return this->_fixedPoint >> Fixed::_bits;
}

std::ostream & 		operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
