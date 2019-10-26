/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:27:15 by hypark            #+#    #+#             */
/*   Updated: 2019/10/26 01:57:34 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_st(t_cw *cw, t_process *cp)
{
	int32_t			store;
	int16_t			address;
	int8_t			*reg_byte;
	int8_t			i;

	store = cp->registers[cp->param_value[0]];
	FLAG & FL_VER4 ? ft_printf("P%5d | st r%d ", P_I, cp->param_value[0]) : 0;
	if (cp->param_type[1] == T_REG)
	{
		cp->registers[cp->param_value[1]] = store;
		FLAG & FL_VER4 ? ft_printf("r%d ", cp->param_value[1]) : 0;
	}
	else if (cp->param_type[1] == T_IND)
	{
		address = (int16_t)cp->param_value[1];
		FLAG & FL_VER4 ? ft_printf("%d\n", address) : 0;
		address = pc_idx_mod(cp, address);
		swap_int32(&store);
		reg_byte = (int8_t *)(&store); 
		i = -1;
		while (++i < 4)
			cw->memory[(address + i) % MEM_SIZE] = reg_byte[i];
	}
	cp->carry = 1;
}
