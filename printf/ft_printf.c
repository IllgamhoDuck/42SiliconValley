/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:24:16 by hypark            #+#    #+#             */
/*   Updated: 2019/08/15 23:01:55 by hypark           ###   ########.fr       */
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

/*
** when we find {cyan} we set color {eoc} end the color
*/

static void			ft_printf_mod(t_print *p)
{
	int				i;

	p->len = 1;
	p->pad = p->w - p->len;
	if (p->f & FLM)
	{
		print_c(p, '%', 1);
		print_c(p, ' ', p->pad);
	}
	else
	{
		print_c(p, (p->f & FLZ && p->p == -1) ? '0' : ' ', p->pad);
		print_c(p, '%', 1);
	}
	p->output[p->print_len] = '\0';
	p->total_len += p->print_len;
	i = 0;
	while (i < p->print_len)
		ft_putchar(p->output[i++]);
}

static inline void	asterisk_process(t_print *p)
{
	int				width;
	int				precision;

	if (p->w_a)
	{
		width = va_arg(p->ap, int);
		if (!p->w)
		{
			if (width < 0)
			{
				width = -width;
				p->f |= FLM;
			}
			p->w = width;
		}
	}
	if (p->p_a)
	{
		precision = va_arg(p->ap, int);
		if (precision < 0)
			p->p = -1;
		else
			p->p = precision;
	}
}

static void			print_case(t_print *p)
{
	asterisk_process(p);
	if (p->cvs == 'd' || p->cvs == 'i' || p->cvs == 'D')
		ft_printf_di(p);
	else if (p->cvs == 'u' || p->cvs == 'o' || p->cvs == 'x' || p->cvs == 'X')
		ft_printf_uox(p);
	else if (p->cvs == 'f')
		ft_printf_f(p);
	else if (p->cvs == 'c')
		ft_printf_c(p);
	else if (p->cvs == 's')
		ft_printf_s(p);
	else if (p->cvs == 'p')
		ft_printf_p(p);
	else if (p->cvs == '%')
		ft_printf_mod(p);
	else if (p->cvs == 'b' || p->cvs == 'B')
		ft_printf_b(p);
}

inline static int	invalid_check(t_print *p)
{
	if (p->cvs != 'd' && p->cvs != 'i' && p->cvs != 'D' && p->cvs != 'u' &&
		p->cvs != 'o' && p->cvs != 'x' && p->cvs != 'X' && p->cvs != 'f' &&
		p->cvs != 'r' && p->cvs != 'b' && p->cvs != 'B' && p->cvs != 'F' &&
		p->cvs != 'c' && p->cvs != 's' && p->cvs != 'p' && p->cvs != '%')
		return (1);
	return (0);
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
			if (invalid_check(&p))
				break ;
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
