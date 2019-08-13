/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:39:17 by hypark            #+#    #+#             */
/*   Updated: 2019/08/13 01:29:45 by hypark           ###   ########.fr       */
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

inline static void		print_uox(t_print *p, uintmax_t n)
{
	int					i;

	if (p->f & FLM)
	{
		if ((p->cvs == 'x' || p->cvs == 'X') && (p->f & FLH))
			p->f & UPPER ? print_str(p, "0X", 2) : print_str(p, "0x", 2);
		print_c(p, '0', p->p_pad);
		store_n_base(p, n, p->base, (p->f & UPPER) >> 10);
		print_c(p, (p->f & FLZ && p->p == -1) ? '0' : ' ', p->pad);
	}
	else
	{
		print_c(p, (p->f & FLZ && p->p == -1) ? '0' : ' ', p->pad);
		if ((p->cvs == 'x' || p->cvs == 'X') && (p->f & FLH))
			p->f & UPPER ? print_str(p, "0X", 2) : print_str(p, "0x", 2);
		print_c(p, '0', p->p_pad);
		store_n_base(p, n, p->base, (p->f & UPPER) >> 10);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

static inline void 		get_base(t_print *p)
{
	if (p->cvs == 'o')
		p->base = 8;
	else if (p->cvs == 'u')
		p->base = 10;
	else if (p->cvs == 'x')
		p->base = 16;
	else if (p->cvs == 'X')
	{
		p->base = 16;
		p->f |= UPPER;
	}
}

void					ft_printf_uox(t_print *p)
{
	uintmax_t			n;

	n = get_uint(p);
	get_base(p);
	p->len += count_base(n, p->base);
	if (p->p != -1)
	{
		p->p_pad = (p->p - p->len);
		if (p->p_pad > 0)
			p->len = p->p;
	}
	p->pad = p->w - p->len;
	if ((p->cvs == 'x' || p->cvs == 'X') && (p->f & FLH))
		p->pad -= 2;
	print_uox(p, n);
}
