/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 01:06:11 by hypark            #+#    #+#             */
/*   Updated: 2019/08/13 00:20:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** if the value is -1, it means it has no value
** if precision is 0 it influence the flag 0 doesn't works
** so we need to know there is precision or not
** if there is not precision it is -1
*/

void				init_info(t_print *p)
{
	p->f = 0;
	p->w = 0;
	p->w_a = 0;
	p->p = -1;
	p->p_a = 0;
	p->cvs = 0;
	p->print_len = 0;
	p->p_pad = 0;
	p->pad = 0;
	p->len = 0;
	p->neg = 1;
	p->base = 10;
}
