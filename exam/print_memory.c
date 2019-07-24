/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:52:06 by hypark            #+#    #+#             */
/*   Updated: 2018/06/01 15:16:40 by hypark           ###   ########.fr       */
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

void		ft_printhex(int nb)
{
	int		digit;

	digit = 0;
	if (nb >= 16)
		ft_printhex(nb / 16);
	digit = nb % 16 + ((nb % 16) < 10 ? '0' : 'a' - 10);
	ft_putchar(digit);
}

void		ft_printchars(char c)
{
	ft_putchar((c >= 32 && c <= 126) ? c : '.');
}

void		print_memory(const void *addr, size_t size)
{
	unsigned char	*tab;
	int				col;	
	size_t			i;
	size_t			tmp;

	col = -1;
	i = 0;
	tmp = 0;
 	tab = (unsigned char *)addr;
	while (i < size)
	{
		col = -1;
		tmp = i;
		while (++col < 16)
		{
			if (i < size)
			{
				if (tab[i] < 16)
					ft_putchar('0');
				ft_printhex(tab[i]);
			}
			else
				ft_putstr("  ");
			if ((i % 2) == 1)
				ft_putchar(' ');
			i++;
		}
		col = -1;
		i = tmp;
		while (++col < 16 && i < size)
			ft_printchars(tab[i++]);
	ft_putchar('\n');
	}
}

int			main(void)
{
	int		tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
