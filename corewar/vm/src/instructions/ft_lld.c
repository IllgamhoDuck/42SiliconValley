/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:27:21 by hypark            #+#    #+#             */
/*   Updated: 2019/10/26 23:22:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int32_t		indirect_process(t_cw *cw, t_process *cp, int i)
{
	int16_t			address;
	int32_t			param;
	int8_t			*param_byte;

	param_byte = (int8_t *)(&param);
	address = (int16_t)cp->param_value[i];
	address += cp->pc;
	if (address < 0)
		address += MEM_SIZE;
	else
		address %= MEM_SIZE;
	i = -1;
	while (++i < 4)
	{
		*param_byte = cw->memory[(address + i) % MEM_SIZE];
		param_byte++;
	}
	swap_int32(&param);
	return (param);
}

static int32_t		param_1(t_cw *cw, t_process *cp)
{
	int16_t			address;
	int32_t			param;
	int8_t			*param_byte;
	int8_t			i;

	if (cp->param_type[0] == T_DIR)
		return (cp->param_value[0]);
	else if (cp->param_type[0] == T_IND)
		return (indirect_process(cw, cp, 0));
	else
		return (0);
}

void				ft_lld(t_cw *cw, t_process *cp)
{
	int32_t			copy;
	uint8_t			*reg_byte;
	int8_t			i;

	copy = param_1(cw, cp);
	cp->registers[cp->param_value[1]] = copy; 
	cp->carry = modify_carry(copy);
	FLAG & FL_VER4 ? ft_printf("P%5d | ", P_I) : 0;
	FLAG & FL_VER4 ? ft_printf("lld %d r%d\n", copy, cp->param_value[1]) : 0;
}

