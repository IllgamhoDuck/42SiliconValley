/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:03:23 by hypark            #+#    #+#             */
/*   Updated: 2020/01/13 21:11:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "class2.hpp"

Sample2::Sample2( char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3) {

	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
}

Sample2::~Sample2( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}