/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:37:56 by hypark            #+#    #+#             */
/*   Updated: 2019/11/13 09:48:21 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

static t_instr_hdlr g_instruction[] = {
	ft_live,
	ft_ld,
	ft_st,
	ft_add,
	ft_sub,
	ft_and,
	ft_or,
	ft_xor,
	ft_zjump,
	ft_ldi,
	ft_sti,
	ft_fork,
	ft_lld,
	ft_lldi,
	ft_lfork,
	ft_aff
};

/*
** ----------------------------------------------------------------------------
** Modifies the carry value.
**
** {int} value - New carry value
** ----------------------------------------------------------------------------
*/

int8_t			modify_carry(int value)
{
	if (value == 0)
		return (1);
	else
		return (0);
}

/*
** ----------------------------------------------------------------------------
** DESCRITPTION
**
** {t_process *} cp -
** {int16_t} offset -
** ----------------------------------------------------------------------------
*/

int16_t			pc_relative(t_process *cp, int16_t offset)
{
	offset = cp->pc + offset;
	if (offset < 0)
		return (MEM_SIZE + offset);
	return (offset % MEM_SIZE);
}

/*
** ----------------------------------------------------------------------------
** DESCRITPTION
**
** {t_process *} cp -
** {int16_t} offset -
** ----------------------------------------------------------------------------
*/

int16_t			pc_idx_mod(t_process *cp, int16_t offset)
{
	if (offset < 0)
	{
		offset = ((-1) * offset) % IDX_MOD;
		offset *= -1;
	}
	else
		offset %= IDX_MOD;
	offset = cp->pc + offset;
	if (offset < 0)
		return (MEM_SIZE + offset);
	return (offset % MEM_SIZE);
}

/*
** -----------------------------------------------------------
** Store the information based on the op.c
** When storing the information based on ocp
** check this is right or wrong and if not wrong return 0
**
** {t_cw *} cw - Main structure for corewar.
** {t_process *} cp -
** -----------------------------------------------------------
*/

static int8_t	instruction_get_info(t_cw *cw, t_process *cp)
{
	int8_t		i;
	int8_t		trunc;
	int8_t		*param_byte;

	trunc = g_op_tab[cp->op].trunc;
	if (OCP)
	{
		if (process_ocp(cw, cp, trunc))
			return (1);
	}
	else
	{
		cp->param_type[0] = T_DIR;
		param_byte = (int8_t *)cp->param_value;
		param_byte += 4 - (trunc ? 2 : 4);
		i = -1;
		while (++i < (trunc ? 2 : 4))
		{
			*param_byte = (int8_t)cw->memory[(cp->pc + 1 + i) % MEM_SIZE];
			param_byte++;
		}
		swap_32((uint32_t *)cp->param_value);
		cp->next_pc_distance += 1 + (trunc ? 2 : 4);
	}
	return (0);
}

/*
** ----------------------------------------------------------------------------
** DESCRITPTION
**
** {t_cw *} cw - Main structure for corewar.
** {t_process *} cp -
** ----------------------------------------------------------------------------
*/

void			instruction_proceed(t_cw *cw, t_process *cp)
{
	int8_t		error;

	cp->op_called = 0;
	error = instruction_get_info(cw, cp);
	if (error == 0)
		g_instruction[cp->op](cw, cp);
	if ((cp->op != 8) || cp->carry == 0 || error)
		cp->pc = (cp->pc + cp->next_pc_distance) % MEM_SIZE;
	cp->next_pc_distance = 0;
	bzero(cp->param_type, 3);
	bzero(cp->param_size, 3);
	bzero(cp->param_value, 12);
	cp->init_cycle = CYCLE;
}
