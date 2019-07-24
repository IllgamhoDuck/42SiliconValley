/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:41:18 by hypark            #+#    #+#             */
/*   Updated: 2018/06/04 22:49:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void			ft_print_char_2d(char **arr, int row, int col)
{
	int			i;
	int			j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			ft_putchar(arr[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void			ft_print_int_2d(int **arr, int row, int col)
{
	int			i;
	int			j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			ft_putnbr(arr[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
