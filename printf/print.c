/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:40:29 by hypark            #+#    #+#             */
/*   Updated: 2019/08/11 02:00:24 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

/*
**void				print_info(t_print *p_info)
**{
**	int				i;
**
**	i = 0;
**	printf("\n");
**	while (i < p_info->flag_total)
**		printf("The flag stored is : %c\n", p_info->flag[i++]);
**	printf("The width is : %d\n", p_info->width);
**	printf("The width asterisk is : %d\n", p_info->w_a);
**	printf("The precision is : %d\n", p_info->precision);
**	printf("The precision asterisk is : %d\n", p_info->p_a);
**	if (p_info->length)
**		printf("The length is : %s\n", p_info->length);
**	printf("The format is : %c\n", p_info->format);
**}
*/
