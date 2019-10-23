/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:12:50 by hypark            #+#    #+#             */
/*   Updated: 2019/10/23 01:31:52 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int32_t		param_1(t_cw *cw, t_process *cp)
{
	int16_t			offset;
	int32_t			param;
	int8_t			*param_byte;
	int8_t			i;

	if (cp->param_type[0] == T_REG)
		return (cp->registers[cp->param_value[0]]);
	else if (cp->param_type[0] == T_DIR)
		return (cp->param_value[0]);
	else if (cp->param_type[0] == T_IND)
	{
		offset = (int16_t)cp->param_value[0];
		offset = pc_idx_mod(cp, offset);
		param_byte = (int8_t *)(&param);
		i = -1;
		while (++i < 4)
			*param_byte = cw->memory[(offset + i) % MEM_SIZE];
		swap_32((uint32_t *)&param);
		return (param);
	}
	else
		return (0);
}

static int32_t		param_2(t_cw *cw, t_process *cp)
{
	int16_t			offset;
	int32_t			param;
	int8_t			*param_byte;
	int8_t			i;

	if (cp->param_type[1] == T_REG)
		return (cp->registers[cp->param_value[1]]);
	else if (cp->param_type[1] == T_DIR)
		return (cp->param_value[1]);
	else if (cp->param_type[1] == T_IND)
	{
		offset = (int16_t)cp->param_value[0];
		offset = pc_idx_mod(cp, offset);
		i = -1;
		while (++i < 4)
			*param_byte = cw->memory[(offset + i) % MEM_SIZE];
		swap_32((uint32_t *)&param);
		return (param);
	}
	else
		return (0);
}

void				ft_and(t_cw *cw, t_process *cp)
{
	cp->registers[cp->param_value[2]] = param_1(cw, cp) & param_2(cw, cp);
	cp->carry = 1;
    printf("and called\n");
}
