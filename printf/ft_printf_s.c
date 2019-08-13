/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:03:30 by hypark            #+#    #+#             */
/*   Updated: 2019/08/13 02:11:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			null_str(t_print *p)
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

void					ft_printf_p(t_print *p)
{
	void				*add;

	add = va_arg(p->ap, void *);
	printf("this is address %d", (int)add);
}
