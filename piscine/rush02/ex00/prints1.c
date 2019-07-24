/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:28:15 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/06/03 23:30:08 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void			ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void			ft_print(int col, int row, int r, int rush)
{
	if (r == 0)
	{
		ft_putstr("[rush-0");
		ft_putnbr(rush);
		ft_putstr("] [");
		ft_putnbr(row);
		ft_putstr("] [");
		ft_putnbr(col);
		ft_putstr("]");
	}
}

int				ft_row_len(char *str)
{
	int			row;

	row = 0;
	if (!(*str))
		return (0);
	while (*str)
	{
		if (*str == '\n')
			row++;
		str++;
	}
	if (*(str - 1) != '\n')
		row++;
	return (row);
}
