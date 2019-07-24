/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:50:38 by exam              #+#    #+#             */
/*   Updated: 2018/06/01 20:04:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int			ft_atoi(char *str)
{
	int		result;

	result = 0;
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

void		ft_putnbr(int nb)
{
	char	result;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	result = (nb % 10) + '0';
	ft_putchar(result);
}

void		ft_tab_mult(int mul)
{
	int		i;

	i = 0;
	while (++i < 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(mul);
		ft_putstr(" = ");
		ft_putnbr(mul * i);
		ft_putchar('\n');
	}
}

int			main(int argc, char **argv)
{
	int		mul;

	mul = 0;
	if (argc < 2)
	{
		ft_putchar('\n');
	}
	else
	{
		mul = ft_atoi(argv[1]);
		ft_tab_mult(mul);
	}
	return (0);
}
