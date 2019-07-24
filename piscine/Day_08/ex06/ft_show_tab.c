/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 22:55:55 by hypark            #+#    #+#             */
/*   Updated: 2018/05/25 23:37:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void		ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void		ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void		ft_print_words_tables(char **tab)
{
	int		i;
	int		n_add;

	i = 0;
	n_add = 0;
	while (tab[i++] != 0)
		n_add++;
	i = 0;
	while (i <= n_add)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void		ft_show_tab(t_stock_par *par)
{
	t_stock_par		*cp_par;
	int				stock_len;
	int				i;

	i = 0;
	stock_len = 0;
	cp_par = par;
	while (cp_par->str)
	{
		cp_par++;
		stock_len++;
	}
	while (i < stock_len)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[i].tab);
	}
}
