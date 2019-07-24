/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:06:58 by hypark            #+#    #+#             */
/*   Updated: 2018/05/20 14:13:43 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		rush_putchar(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || (i != 1 && j != 1 && i == x && j == y))
		ft_putchar('/');
	else if ((i == 1 && j == y) || (i == x && j == 1))
		ft_putchar('\\');
	else if (i == 1 || j == 1 || i == x || j == y)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void		rush(int x, int y)
{
	int		i;
	int		j;

	if (x >= 0 && y >= 0)
	{
		j = 1;
		while (j <= y)
		{
			i = 1;
			while (i <= x)
			{
				rush_putchar(x, y, i, j);
				i++;
			}
			ft_putchar('\n');
			j++;
		}
	}
}
