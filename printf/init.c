/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 01:06:11 by hypark            #+#    #+#             */
/*   Updated: 2019/08/11 02:36:03 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** if the value is -1, it means it has no value
** if precision is 0 it influence the flag 0 doesn't works
** so we need to know there is precision or not
** if there is not precision it is -1
*/

void				init_info(t_print *p_info)
{
	p_info->flag[0] = 0;
	p_info->flag_total = 0;
	p_info->width = 0;
	p_info->w_a = 0;
	p_info->precision = -1;
	p_info->p_a = 0;
	p_info->length = 0;
	p_info->format = 0;
	p_info->color = -1;
}
