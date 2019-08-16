/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:59:05 by hypark            #+#    #+#             */
/*   Updated: 2019/08/14 05:41:31 by hypark           ###   ########.fr       */
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
	int					i;

	s = va_arg(p->ap, char *);
	if (s == NULL)
		return (null_str(p));
	p->len = (int)ft_strlen(s);
	if (p->p != -1 && p->p < p->len)
		p->len = p->p;
	p->pad = p->w - p->len;
	if (p->f & FLM)
	{
		print_str(p, s, p->len);
		print_c(p, ' ', p->pad);
	}
	else
	{
		print_c(p, ' ', p->pad);
		print_str(p, s, p->len);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

inline static void		printf_0_23(void)
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

void					ft_printf_r(t_print *p)
{
	int				i;

	printf_0_23();
}
