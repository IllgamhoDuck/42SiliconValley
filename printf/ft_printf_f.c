/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:04:44 by hypark            #+#    #+#             */
/*   Updated: 2019/08/15 21:38:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double		get_float(t_print *p)
{
	long double			n;

	if (p->f & L2)
		n = va_arg(p->ap, long double);
	else
		n = (long double)va_arg(p->ap, double);
	return (n);
}

inline static void		print_f(t_print *p, uintmax_t n, long double f)
{
	int					i;

	if (p->f & FLM)
	{
		print_sign(p);
		p->f & NP ? 0 : store_n_base(p, n, 10, 0);
		p->p == 0 && !(p->f & FLH) ? 0 : print_c(p, '.', 1);
		p->p > 0 ? print_decimal(p, f, p->p) : 0;
		print_c(p, ' ', p->pad);
	}
	else
	{
		p->f & FLZ ? print_sign(p) : 0;
		print_c(p, p->f & FLZ ? '0' : ' ', p->pad);
		p->f & FLZ ? 0 : print_sign(p);
		p->f & NP ? 0 : store_n_base(p, n, 10, 0);
		p->p == 0 && !(p->f & FLH) ? 0 : print_c(p, '.', 1);
		p->p > 0 ? print_decimal(p, f, p->p) : 0;
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

void					ft_printf_f(t_print *p)
{
	long double			f;
	uintmax_t			n;

	f = get_float(p);
	p->f |= f < 0 ? NEG : 0;
	f = f < 0 ? -f : f;
	n = (uintmax_t)f;
	f = f - (uintmax_t)f;
	if (p->p == 0 && (uint8_t)(f * 10) > 5)
		n += 1;
	p->len += count_base(n, 10);
	if (p->p == -1)
		p->p = 6;
	p->pad = p->w - p->len - (p->p == 0 ? 0 : p->p);
	if ((p->f & FLS) || (p->f & FLP) || p->f & NEG)
		p->pad -= 1;
	if (p->f & FLH || p->p != 0)
		p->pad -= 1;
	print_f(p, n, f);
}
