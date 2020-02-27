/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:23:38 by hypark            #+#    #+#             */
/*   Updated: 2020/01/13 21:59:07 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "struct.hpp"

Structure::Structure( void ) {

	std::cout << "Constructor called" << std::endl;

	return ;
}

Structure::~Structure( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}
