/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:11:19 by hypark            #+#    #+#             */
/*   Updated: 2020/01/14 20:19:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void		byPtr(std::string* str)
{
	*str += " and ponies";
}

void		byConstPtr(std::string const * str)
{
	std::cout << *str << std::endl;
}

void		byRef(std::string& str)
{
	str += " and ponies";
}

// const std::string const* str = std::string const &(const *) std
void		byConstRef(std::string const & str)
{
	std::cout << str << std::endl;
}

int			main()
{
	std::string str = "i like butterflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";
	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);
	return 0;
};
