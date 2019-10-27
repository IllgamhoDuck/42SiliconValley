/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:39:44 by hypark            #+#    #+#             */
/*   Updated: 2019/10/26 23:22:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

static int32_t		indirect_process(t_cw *cw, t_process *cp, int i)
{
	int16_t			address;
	int16_t			param;
	int8_t			*param_byte;

	param_byte = (int8_t *)(&param);
	address = (int16_t)cp->param_value[i];
	address += cp->pc;
	if (address < 0)
		address += MEM_SIZE;
	else
		address %= MEM_SIZE;
	i = -1;
	while (++i < IND_SIZE)
	{
		*param_byte = cw->memory[(address + i) % MEM_SIZE];
		param_byte++;
	}
	param = ((param & 0x00FF) << 8) | ((param & 0xFF00) >> 8);
	return ((int32_t)param);
}

static int32_t		param_1(t_cw *cw, t_process *cp)
{
	int32_t			param;

	if (cp->param_type[0] == T_REG)
	{
		FLAG & FL_VER4 ? ft_printf("r%d ", cp->param_value[0]) : 0;
		return (cp->registers[cp->param_value[0]]);
	}
	else if (cp->param_type[0] == T_DIR)
	{
		param = (int32_t)(int16_t)cp->param_value[0];
		FLAG & FL_VER4 ? ft_printf("%d ", param) : 0;
		return (param);
	}
	else if (cp->param_type[0] == T_IND)
	{
		param = indirect_process(cw, cp, 0);
		FLAG & FL_VER4 ? ft_printf("%d", param) : 0;
		return (param);
	}
	else
		return (0);
}

static int32_t		param_2(t_cw *cw, t_process *cp)
{
	int32_t			param;

	if (cp->param_type[1] == T_REG)
	{
		FLAG & FL_VER4 ? ft_printf("r%d\n", cp->param_value[1]) : 0;
		return (cp->registers[cp->param_value[1]]);
	}
	else if (cp->param_type[1] == T_DIR)
	{
		param = (int32_t)(int16_t)cp->param_value[1];
		FLAG & FL_VER4 ? ft_printf("%d\n", param) : 0;
		return (param);
	}
	else
		return (0);
}

void				ft_lldi(t_cw *cw, t_process *cp)
{
	int32_t			offset;
	int32_t			param1;
	int32_t			param2;
	int8_t			*reg_byte;
	int8_t			i;

	FLAG & FL_VER4 ? ft_printf("P%5d | ", P_I) : 0;
	FLAG & FL_VER4 ? ft_printf("lldi r%d ", cp->param_value[0]) : 0;
	param1 = param_1(cw, cp);
	param2 = param_1(cw, cp);
	offset = param1 + param2;
	offset += cp->pc;
	if (offset < 0)
		offset += MEM_SIZE;
	else
		offset %= MEM_SIZE;
	reg_byte = (int8_t *)(&cp->registers[cp->param_value[2]]); 
	i = -1;
	while (++i < 4)
		 reg_byte[3 - i] = cw->memory[(offset + i) % MEM_SIZE];
	cp->carry = modify_carry(cp->registers[cp->param_value[2]]);
}	
