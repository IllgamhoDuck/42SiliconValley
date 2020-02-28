/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:29:25 by hypark            #+#    #+#             */
/*   Updated: 2020/01/13 23:42:51 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void			ft_putchar( char c ) {

	std::cout << c; 
}

int				is_small_char( char c ) {

	return c >= 'a' && c <= 'z';
}

void			megaphone( char *str ) {

	while (*str)
	{
		if (is_small_char(*str))
			ft_putchar(*str - 32);
		else
			ft_putchar(*str);
		str++;
	}
}

int				main( int ac, char **av ) {

	int			i = 0;

	if (ac > 1)
	{
		while (++i < ac)
			megaphone(av[i]);
		std::cout << std::endl;
	}
	return 0;
}
