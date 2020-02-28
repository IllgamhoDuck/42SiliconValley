/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:00:44 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 23:04:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int				main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *strPtr = &string;
	std::string &strRef = string;
	
	std::cout << string << std::endl;
	std::cout << *strPtr << std::endl;
	std::cout << strRef << std::endl;
	return 0;
}
