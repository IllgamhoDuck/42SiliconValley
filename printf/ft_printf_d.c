/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 01:56:10 by hypark            #+#    #+#             */
/*   Updated: 2019/08/11 02:44:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_printf_d(t_print *p_info)
{
	int				result;
	if (p_info->length == 0)
	{
		result = va_arg(p_info->ap, int);
		ft_putnbr(result);
		printf("\n");
	}
	printf("width is %d\n", p_info->width);
	printf("precision is %d\n", p_info->precision);
}
