/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:38:29 by hypark            #+#    #+#             */
/*   Updated: 2019/08/16 01:41:57 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static intmax_t	get_int(t_print *p)
{
	intmax_t			n;

	if (p->f & L)
		n = va_arg(p->ap, long);
	else if (p->f & LL)
		n = va_arg(p->ap, long long);
	else
		n = va_arg(p->ap, int);
	if (p->f & H)
		n = (short)n;
	else if (p->f & HH)
		n = (char)n;
	return (n);
}

inline static void		print_di(t_print *p, uintmax_t n)
{
	int					i;

	if (p->f & FLM)
	{
		print_sign(p);
		print_c(p, '0', p->p_pad);
		p->f & NP ? 0 : store_n_base(p, n, 10, 0);
		print_c(p, ' ', p->pad);
	}
	else
	{
		p->f & FLZ && p->p == -1 ? print_sign(p) : 0;
		print_c(p, (p->f & FLZ && p->p == -1) ? '0' : ' ', p->pad);
		p->f & FLZ && p->p == -1 ? 0 : print_sign(p);
		print_c(p, '0', p->p_pad);
		p->f & NP ? 0 : store_n_base(p, n, 10, 0);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar_fd(p->output[i++], p->fd);
}

void					ft_printf_di(t_print *p)
{
	intmax_t			n1;
	uintmax_t			n2;

	n1 = get_int(p);
	p->f |= n1 < 0 ? NEG : 0;
	n2 = n1 < 0 ? -n1 : n1;
	p->len += count_base(n2, 10);
	p->f |= (p->p == 0 && n2 == 0) ? NP : 0;
	if (p->p != -1)
	{
		p->p_pad = (p->p - p->len);
		if (p->p_pad > 0)
			p->len = p->p;
	}
	p->f & NP ? p->len-- : 0;
	p->pad = p->w - p->len;
	if ((p->f & FLS) || (p->f & FLP) || p->f & NEG)
		p->pad -= 1;
	print_di(p, n2);
}
