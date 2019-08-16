/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:46:35 by hypark            #+#    #+#             */
/*   Updated: 2019/08/15 22:41:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int			count_base(uintmax_t n, uint8_t base)
{
	int				len;

	len = 0;
	while (n >= base)
	{
		len++;
		n /= base;
	}
	len++;
	return (len);
}

static char			get_base_c(int n, int u)
{
	char			*hex_u;
	char			*hex_d;

	hex_u = "0123456789ABCDEF";
	hex_d = "0123456789abcdef";
	return (u == 1 ? hex_u[n] : hex_d[n]);
}

/*
** u - upper if u is 1 than upper case is printed
** is 0 than lower case will be printed
*/

void				store_n_base(t_print *p, uintmax_t n, int base, int u)
{
	uint8_t			b;

	b = base;
	if (n >= b)
		store_n_base(p, n / b, base, u);
	p->output[p->print_len++] = get_base_c(n % b, u);
}
