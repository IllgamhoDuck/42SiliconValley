/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:42:33 by hypark            #+#    #+#             */
/*   Updated: 2019/08/16 01:43:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			print_c_unlimit(t_print *p, char c, int n)
{
	int				i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar_fd(c, p->fd);
		p->print_len++;
	}
}

inline void			print_str_unlimit(t_print *p, char *str, int len)
{
	int				i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar_fd(str[i], p->fd);
		p->print_len++;
		i++;
	}
}
