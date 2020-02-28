/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:23:38 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 01:06:09 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "class.hpp"

Sample::Sample( void ) {

	std::cout << "Constructor called" << std::endl;
//	Sample::_nbInst += 1;
	return ;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
//	Sample::_nbInst -= 1;
	return ;
}

void		Sample::bar( void ) const {

	std::cout << "Member function bar called" << std::endl;
	return ;
}

//int		Sample::getNbInst( void ) {
//	
//	return Sample::_nbInst;
//}
//
//
//int		Sample::_nbInst = 0;

// const at the end means this function will not modify this instance
//int			Sample::getFoo( void ) const {
//
//	return this->_foo;
//}
//
//void		Sample::setFoo( int v ) {
//
//	if ( v >= 0 )
//		this->_foo = v;
//	return ;
//}
//
//int			Sample::compare( Sample * other ) const {
//
//	if ( this->_foo < other->getFoo() )
//		return -1;
//	else if ( this->_foo > other->getFoo() )
//		return 1;
//	return 0;
//}
