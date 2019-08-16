/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:59:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/16 00:40:28 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_printf_c(t_print *p)
{
	int					i;
	char				c;

	p->len = 1;
	c = (char)va_arg(p->ap, int);
	p->pad = p->w - p->len;
	if (p->f & FLM)
	{
		print_c(p, c, 1);
		print_c(p, ' ', p->pad);
	}
	else
	{
		print_c(p, ' ', p->pad);
		print_c(p, c, 1);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

static void				null_str(t_print *p)
{
	int					i;

	p->len = 6;
	if (p->p != -1 && p->p < p->len)
		p->len = p->p;
	p->pad = p->w - p->len;
	if (p->f & FLM)
	{
		print_str(p, "(null)", p->len);
		print_c(p, ' ', p->pad);
	}
	else
	{
		print_c(p, ' ', p->pad);
		print_str(p, "(null)", p->len);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

void					ft_printf_s(t_print *p)
{
	char				*s;

	s = va_arg(p->ap, char *);
	if (s == NULL)
		return (null_str(p));
	p->len = (int)ft_strlen(s);
	if (p->p != -1 && p->p < p->len)
		p->len = p->p;
	p->pad = p->w - p->len;
	if (p->f & FLM)
	{
		print_str_unlimit(p, s, p->len);
		print_c_unlimit(p, ' ', p->pad);
	}
	else
	{
		print_c_unlimit(p, ' ', p->pad);
		print_str_unlimit(p, s, p->len);
	}
	p->total_len += p->print_len;
}

inline static void		printf_p(t_print *p, uintmax_t addr)
{
	int					i;

	if (p->f & FLM)
	{
		print_str(p, "0x", 2);
		print_c(p, '0', p->p_pad);
		p->f & NP ? 0 : store_n_base(p, addr, 16, 0);
		print_c(p, ' ', p->pad);
	}
	else
	{
		p->f & FLZ && p->p == -1 ? print_str(p, "0x", 2) : 0;
		print_c(p, p->f & FLZ && p->p == -1 ? '0' : ' ', p->pad);
		!(p->f & FLZ && p->p == -1) ? print_str(p, "0x", 2) : 0;
		print_c(p, '0', p->p_pad);
		p->f & NP ? 0 : store_n_base(p, addr, 16, 0);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

void					ft_printf_p(t_print *p)
{
	uintmax_t			addr;

	addr = (uintmax_t)va_arg(p->ap, void *);
	p->len += count_base(addr, 16);
	p->f |= (p->p == 0 && addr == 0) ? NP : 0;
	if (p->p != -1)
	{
		p->p_pad = (p->p - p->len);
		if (p->p_pad > 0)
			p->len = p->p;
	}
	p->f & NP ? p->len-- : 0;
	p->pad = p->w - p->len - 2;
	printf_p(p, addr);
}
