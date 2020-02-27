/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:46:23 by hypark            #+#    #+#             */
/*   Updated: 2019/11/13 22:07:37 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

/*
** ----------------------------------------------------------------------------
** DESCRITPTION
**
** {t_cw *} cw -
** {t_process *} cp -
** ----------------------------------------------------------------------------
*/

static inline int32_t		indirect_process(t_cw *cw, t_process *cp, int i)
{
	int16_t			address;
	int16_t			param;
	int8_t			*param_byte;

	param_byte = (int8_t *)(&param);
	address = (int16_t)cp->param_value[i];
	address = pc_idx_mod(cp, address);
	i = -1;
	while (++i < IND_SIZE)
	{
		*param_byte = cw->memory[(address + i) % MEM_SIZE];
		param_byte++;
	}
	param = ((param & 0x00FF) << 8) | ((param & 0xFF00) >> 8);
	return ((int32_t)param);
}

/*
** ----------------------------------------------------------------------------
** DESCRITPTION
**
** {t_cw *} cw -
** {t_process *} cp -
** ----------------------------------------------------------------------------
*/

static inline int32_t		param_1(t_cw *cw, t_process *cp)
{
	int32_t			param;

	if (cp->param_type[1] == T_REG)
	{
		param = cp->registers[cp->param_value[1]];
		FLAG & FL_VER4 ? ft_printf("%d ", param) : 0;
		return (param);
	}
	else if (cp->param_type[1] == T_DIR)
	{
		param = (int32_t)(int16_t)cp->param_value[1];
		FLAG & FL_VER4 ? ft_printf("%d ", param) : 0;
		return (param);
	}
	else if (cp->param_type[1] == T_IND)
	{
		param = indirect_process(cw, cp, 1);
		FLAG & FL_VER4 ? ft_printf("%d", param) : 0;
		return (param);
	}
	else
		return (0);
}

/*
** ----------------------------------------------------------------------------
** DESCRITPTION
**
** {t_cw *} cw -
** {t_process *} cp -
** ----------------------------------------------------------------------------
*/

static inline int32_t		param_2(t_cw *cw, t_process *cp)
{
	int32_t			param;

	if (cp->param_type[2] == T_REG)
	{
		param = cp->registers[cp->param_value[2]];
		FLAG & FL_VER4 ? ft_printf("%d\n", param) : 0;
		return (param);
	}
	else if (cp->param_type[2] == T_DIR)
	{
		param = (int32_t)(int16_t)cp->param_value[2];
		FLAG & FL_VER4 ? ft_printf("%d\n", param) : 0;
		return (param);
	}
	else
		return (0);
}

void						ft_sti(t_cw *cw, t_process *cp)
{
	int32_t			offset;
	int32_t			param1;
	int32_t			param2;
	int8_t			*reg_byte;
	int8_t			i;

	FLAG & FL_VER4 ? ft_printf("P%5d | ", P_I) : 0;
	FLAG & FL_VER4 ? ft_printf("sti r%d ", cp->param_value[0]) : 0;
	param1 = param_1(cw, cp);
	param2 = param_2(cw, cp);
	FLAG & FL_VER4 ? ft_printf("       | ") : 0;
	FLAG & FL_VER4 ? ft_printf("-> store to %d + %d", param1, param2) : 0;
	FLAG & FL_VER4 ? ft_printf(" = %d ", param1 + param2) : 0;
	offset = pc_idx_mod(cp, param1 + param2);
	FLAG & FL_VER4 ? ft_printf("(with pc and mod %d)\n", offset) : 0;
	reg_byte = (int8_t *)(&cp->registers[cp->param_value[0]]);
	i = -1;
	while (++i < 4)
	{
		cw->memory[(offset + i) % MEM_SIZE] = reg_byte[3 - i];
		cw->owner[(offset + i) % MEM_SIZE] = cp->id->prog_number - 1;
	}
}