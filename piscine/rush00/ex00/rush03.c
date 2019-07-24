/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:58:57 by hule              #+#    #+#             */
/*   Updated: 2018/05/19 16:20:30 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush_putchar(int x, int y, int i, int j)
{
	if (i == 0 && (j == 0 || j == y - 1))
	{
		ft_putchar('A');
	}
	else if (i == x - 1 && (j == 0 || j == y - 1))
	{
		ft_putchar('C');
	}
	else if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int j;
	int i;

	if (x >= 0 && y >= 0)
	{
		j = 0;
		while (j < y)
		{
			i = 0;
			while (i < x)
			{
				rush_putchar(x, y, i, j);
				i++;
			}
			ft_putchar('\n');
			j++;
		}
	}
}
