/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:42:33 by hypark            #+#    #+#             */
/*   Updated: 2019/08/15 22:44:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			print_c_unlimit(t_print *p, char c, int n)
{
	int				i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar(c);
		p->print_len++;
	}
}

inline void			print_str_unlimit(t_print *p, char *str, int len)
{
	int				i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar(str[i]);
		p->print_len++;
		i++;
	}
}
