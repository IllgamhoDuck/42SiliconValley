/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:46:23 by hypark            #+#    #+#             */
/*   Updated: 2019/10/23 01:27:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

static int32_t		param_1(t_process *cp)
{
	if (cp->param_type[1] == T_REG)
		return (cp->registers[cp->param_value[1]]);
	else if (cp->param_type[1] == T_DIR || cp->param_type[1] == T_IND)
		return ((int32_t)(int16_t)cp->param_value[1]);
	else
		return (0);
}

static int32_t		param_2(t_process *cp)
{
	if (cp->param_type[2] == T_REG)
		return (cp->registers[cp->param_value[2]]);
	else if (cp->param_type[2] == T_DIR)
		return ((int32_t)(int16_t)cp->param_value[2]);
	else
		return (0);
}

void				ft_sti(t_cw *cw, t_process *cp)
{
	int32_t			offset;
	uint8_t			*reg_byte;
	int8_t			i;

	offset = pc_idx_mod(cp, param_1(cp) + param_2(cp));
	reg_byte = (uint8_t *)(&cp->registers[cp->param_value[0]]); 
	i = -1;
	while (++i < 4)
		cw->memory[(offset + i) % MEM_SIZE] = reg_byte[i];
    printf("sti called\n");
}
