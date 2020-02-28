/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:05:35 by hypark            #+#    #+#             */
/*   Updated: 2020/01/16 01:51:07 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)
{
	return ;
}

Fixed::Fixed(int const n) : _fixedPoint(n << Fixed::_bits)
{
	return ;
}

Fixed::Fixed(float const z) : _fixedPoint(std::roundf(z * (1 << Fixed::_bits)))
{
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

// Assign operator
Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits();
	return *this;
}

// Comparison operators
bool 	Fixed::operator>(Fixed const & rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool 	Fixed::operator<(Fixed const & rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool 	Fixed::operator>=(Fixed const & rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool 	Fixed::operator<=(Fixed const & rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool 	Fixed::operator==(Fixed const & rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

// Arithmetic operators
Fixed 	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed 	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed 	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed 	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// pre, post - increment
Fixed &	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed 	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

// pre, post - decrement
Fixed &	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed 	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return temp;
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

// Max & Min function Non member
Fixed & max(Fixed & c1, Fixed & c2)
{
	if (c1 >= c2)
		return c1;
	else
		return c2;
}

Fixed & min(Fixed & c1, Fixed & c2)
{
	if (c1 <= c2)
		return c1;
	else
		return c2;
}

Fixed const & max(Fixed const & c1, Fixed const & c2)
{
	if (c1 >= c2)
		return c1;
	else
		return c2;
}

Fixed const & min(Fixed const & c1, Fixed const & c2)
{
	if (c1 <= c2)
		return c1;
	else
		return c2;
}
