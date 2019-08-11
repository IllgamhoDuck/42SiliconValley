/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:24:16 by hypark            #+#    #+#             */
/*   Updated: 2019/08/11 02:41:26 by hypark           ###   ########.fr       */
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

static void			print_case(t_print *p_info)			
{
	if (p_info->w_a)
		p_info->width = va_arg(p_info->ap, int);
	if (p_info->p_a)
		p_info->precision = va_arg(p_info->ap, int);
	if (p_info->format == 'd' || p_info->format == 'i')
		ft_printf_d(p_info);
}

int					ft_printf(const char *str, ...)
{
	t_print			p_info;

	va_start(p_info.ap, str);
	while (*str)
	{
		init_info(&p_info);
		if (*str == '%')
			str = read_information(++str, &p_info);
		if (p_info.format)
			print_case(&p_info);
		else
			ft_putchar(*str);
		str++;
	}
	va_end(p_info.ap);
	return (0);
}
