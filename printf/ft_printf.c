/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:24:16 by hypark            #+#    #+#             */
/*   Updated: 2019/08/12 13:38:23 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** #define va_start(ap, v) ((ap) = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v))
** _ADDRESSOR(v) &(v)
** _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
** #define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
** #define va_end(ap) (ap = (va_list)0)
*/

// when we find {cyan} we set color {eoc} end the color

static void			ft_printf_mod(t_print *p)
{
	p = 0;
}

static void			print_case(t_print *p)			
{
	if (p->w_a)
		p->w = va_arg(p->ap, int);
	if (p->p_a)
		p->p = va_arg(p->ap, int);
	//print_info(p);
	if (p->format == 'd' || p->format == 'i' || p->format == 'D')
		ft_printf_d(p);
	else if (p->format == '%')
		ft_printf_mod(p);
}

int					ft_printf(const char *str, ...)
{
	t_print			p;

	p.total_len = 0;
	va_start(p.ap, str);
	while (*str)
	{
		init_info(&p);
		if (*str == '%')
		{
			str = read_information(++str, &p);
			print_case(&p);
		}
		else
		{
			ft_putchar(*str);
			p.total_len++;
		}
		str++;
	}
	va_end(p.ap);
	return (p.total_len);
}
