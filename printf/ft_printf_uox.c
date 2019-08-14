/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:39:17 by hypark            #+#    #+#             */
/*   Updated: 2019/08/13 18:53:31 by hypark           ###   ########.fr       */
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
		if (p->hash)
			print_str(p, p->hash, p->cvs == 'o' ? 1 : 2);
		print_c(p, '0', p->p_pad);
		p->f & NP ? 0 : store_n_base(p, n, p->base, (p->f & UPPER) >> 10);
		print_c(p, ' ', p->pad);
	}
	else
	{
		if (p->hash && (p->f & FLZ && p->p == -1))
			print_str(p, p->hash, p->cvs == 'o' ? 1 : 2);
		print_c(p, (p->f & FLZ && p->p == -1) ? '0' : ' ', p->pad);
		if (p->hash && !(p->f & FLZ && p->p == -1))
			print_str(p, p->hash, p->cvs == 'o' ? 1 : 2);
		print_c(p, '0', p->p_pad);
		p->f & NP ? 0 : store_n_base(p, n, p->base, (p->f & UPPER) >> 10);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

static inline void 		get_base(t_print *p, uintmax_t n)
{
	if (p->cvs == 'o')
	{
		p->hash = p->f & FLH ? "0" : 0;
		p->base = 8;
	}
	else if (p->cvs == 'u')
		p->base = 10;
	else if (p->cvs == 'x')
	{
		p->hash = p->f & FLH && n ? "0x" : 0;
		p->base = 16;
	}
	else if (p->cvs == 'X')
	{
		p->hash = p->f & FLH && n ? "0X" : 0;
		p->base = 16;
		p->f |= UPPER;
	}
}

void					ft_printf_uox(t_print *p)
{
	uintmax_t			n;

	n = get_uint(p);
	get_base(p, n);
	p->len += count_base(n, p->base);
	p->f |= (p->p == 0 && n == 0) ? NP : 0;
	p->f |= (p->cvs == 'o' && n == 0 && p->f & FLH) ? NP : 0;
	p->cvs == 'o' && p->f & NP ? p->len-- : 0;
	if (p->p != -1)
	{
		p->p_pad = (p->p - p->len);
		if (p->p_pad > 0)
		{
			p->len = p->p;
			p->cvs == 'o' ? p->f &= ~FLH : 0;
			p->cvs == 'o' ? p->hash = 0 : 0;
		}
	}
	!(p->cvs == 'o') && p->f & NP ? p->len-- : 0;
	p->pad = p->w - p->len;
	if ((p->cvs == 'x' || p->cvs == 'X') && (p->f & FLH) && n)
		p->pad -= 2;
	else if (p->cvs == 'o' && p->f & FLH && (p->p == -1 || p->p_pad <= 0))
		p->pad -= 1;
	print_uox(p, n);
}
