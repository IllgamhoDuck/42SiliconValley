/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:39:17 by hypark            #+#    #+#             */
/*   Updated: 2019/08/14 05:42:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static uintmax_t	get_uint(t_print *p)
{
	uintmax_t			n;

	if (p->f & L)
		n = va_arg(p->ap, unsigned long);
	else if (p->f & LL)
		n = va_arg(p->ap, unsigned long long);
	else
		n = va_arg(p->ap, unsigned int);
	if (p->f & H)
		n = (unsigned short)n;
	else if (p->f & HH)
		n = (unsigned char)n;
	return (n);
}

inline static void		print_b(t_print *p, uintmax_t n)
{
	int					i;

	if (p->f & FLM)
	{
		if (p->f & FLH)
			print_str(p, p->cvs == 'B' ? "0B" : "0b", 2);
		print_c(p, '0', p->p_pad);
		store_n_base(p, n, p->base, 0);
		print_c(p, ' ', p->pad);
	}
	else
	{
		if (p->f & FLH && p->f & FLZ)
			print_str(p, p->cvs == 'B' ? "0B" : "0b", 2);
		print_c(p, p->f & FLZ ? '0' : ' ', p->pad);
		if (p->f & FLH && !(p->f & FLZ))
			print_str(p, p->cvs == 'B' ? "0B" : "0b", 2);
		print_c(p, '0', p->p_pad);
		store_n_base(p, n, p->base, 0);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

void					ft_printf_b(t_print *p)
{
	uintmax_t			n;

	n = get_uint(p);
	p->base = 2;
	p->len += count_base(n, p->base);
	if (p->p != -1)
	{
		p->p_pad = (p->p - p->len);
		if (p->p_pad > 0)
			p->len = p->p;
	}
	p->pad = p->w - p->len;
	if (p->f & FLH)
		p->pad -= 2;
	print_b(p, n);
}
