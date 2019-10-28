/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:40:30 by hypark            #+#    #+#             */
/*   Updated: 2019/10/27 22:05:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_add(t_cw *cw, t_process *cp)
{
	int32_t			add1;
	int32_t			add2;

	FLAG & FL_VER4 ? ft_printf("P%5d | add ", P_I) : 0;
	FLAG & FL_VER4 ? ft_printf("r%d ", cp->param_value[0]) : 0;
	FLAG & FL_VER4 ? ft_printf("r%d ", cp->param_value[1]) : 0;
	FLAG & FL_VER4 ? ft_printf("r%d\n", cp->param_value[2]) : 0;
	add1 = cp->registers[cp->param_value[0]];
	add2 = cp->registers[cp->param_value[1]];
	cp->registers[cp->param_value[2]] = add1 + add2;
	cp->carry = modify_carry(cp->registers[cp->param_value[2]]);
}
