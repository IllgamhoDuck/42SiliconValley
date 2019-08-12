/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 01:56:10 by hypark            #+#    #+#             */
/*   Updated: 2019/08/12 13:30:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		get_nbr(t_print *p)
{
	intmax_t		n;

	if (ft_strcmp(p->length, "l") == 0)
		n = va_arg(p->ap, long);
	else if (ft_strcmp(p->length, "ll") == 0)
		n = va_arg(p->ap, long long);
	else
		n = va_arg(p->ap, int);
	if (ft_strcmp(p->length, "h") == 0)
		n = (short)n;
	else if (ft_strcmp(p->length, "hh") == 0)
		n = (char)n;
	return (n);
}

static void			store_nbr(t_print *p, uintmax_t n)
{
	if (n >= 10)
		store_nbr(p, n / 10);
	p->output[p->print_len++] = n % 10 + '0';
}

static void			store_neg(t_print *p, uintmax_t n)
{
	print_sign(p);
	print_p(p);
	store_nbr(p, n);
	print_pad(p);
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
}

static void			store_not_neg(t_print *p, uintmax_t n)
{
	print_pad(p);
	print_sign(p);
	print_p(p);
	store_nbr(p, n);
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
}

void				ft_printf_d(t_print *p)
{
	intmax_t		n1;
	uintmax_t		n2;
	int				i;

	n1 = get_nbr(p);
	p->len = 0;
	p->neg = n1 < 0 ? -1 : 1;
	n2 = n1 < 0 ? -n1 : n1;
	p->len += count_d(n2);
	if (p->p != -1)
	{
		p->p_pad = (p->p - p->len);
		if (p->p_pad > 0)
			p->len = p->p;
	}
	p->pad = p->w - p->len;
	if ((p->f & FLS) || (p->f & FLP) || p->neg == -1)
		p->pad -= 1;
	if (p->f & FLM)
		store_neg(p, n2);
	else
		store_not_neg(p, n2);
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}
