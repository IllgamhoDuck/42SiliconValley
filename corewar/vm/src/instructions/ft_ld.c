/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:14:58 by hypark            #+#    #+#             */
/*   Updated: 2019/10/26 01:13:50 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int32_t		param_1(t_cw *cw, t_process *cp)
{
	int16_t			address;
	int32_t			param;
	int8_t			*param_byte;
	int8_t			i;

	if (cp->param_type[0] == T_DIR)
		return (cp->param_value[0]);
	else if (cp->param_type[0] == T_IND)
	{
		param_byte = (int8_t *)(&param);
		address = (int16_t)cp->param_value[0];
		address = pc_idx_mod(cp, address);
		i = -1;
		while (++i < 4)
		{
			*param_byte = cw->memory[(address + i) % MEM_SIZE];
			param_byte++;
		}
		swap_int32(&param);
		return (param);
	}
	else
		return (0);
}

void				ft_ld(t_cw *cw, t_process *cp)
{
	int32_t			copy;
	uint8_t			*reg_byte;
	int8_t			i;

	copy = param_1(cw, cp);
	cp->registers[cp->param_value[1]] = copy; 
	cp->carry = 1;
	FLAG & FL_VER4 ? ft_printf("P%5d | ", P_I) : 0;
	FLAG & FL_VER4 ? ft_printf("ld %d r%d\n", copy, cp->param_value[1]) : 0;
}
