/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:13:12 by hypark            #+#    #+#             */
/*   Updated: 2019/10/23 00:07:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

/*
** encode = (ocp >> (2 * (3 - i))) & 0x3;
** ocp - 01101100
** i = 0 | 2 * (3 - 0) = 6 | ocp >> 6 -> 01
** i = 1 | 2 * (3 - 1) = 4 | ocp >> 4 -> 10
** i = 2 | 2 * (3 - 2) = 2 | ocp >> 2 -> 11
*/

static void		store_info_ocp(t_process *cp, uint8_t ocp, uint8_t trunc)
{
	int8_t		encode;
	int8_t		i;

	i = -1;
	while (++i < cp->param_num)
	{
		encode = (ocp >> (2 * (3 - i))) & 0x3;
		if (encode == 1)
		{
			cp->param_type[i] = T_REG;
			cp->param_size[i] = 1;
		}
		else if (encode == 2)
		{
			cp->param_type[i] = T_DIR;
			cp->param_size[i] = trunc ? 2 : 4;
		}
		else if (encode == 3)
		{
			cp->param_type[i] = T_IND;
			cp->param_size[i] = 2;
		}
		else
			cp->param_type[i] = 'X';
	}
}

// If it returns 0 then it means no error
// check the pc next move at here
// ========================================
// there is two types of error here
// 1. 00 is in the parameters
// 2. the parameter type is does not match the op

static int8_t	check_ocp_error(t_process *cp)
{
	int8_t		error;
	int8_t		i;

	error = 0;
	i = -1;
	while (++i < cp->param_num)
	{
		if (cp->param_type[i] == 'X')
			error = 1;
		if ((g_op_tab[cp->op].param[i] & cp->param_type[i]) == 0)
			error = 1;
		cp->next_pc_distance += cp->param_size[i];
	}
	if (error)
		return (1);
	return (0);
}

static void		get_param_value(t_cw *cw, t_process *cp)
{
	int8_t		i;
	int8_t		j;
	int8_t		*param_byte;
	uint8_t		parsed_n;
	
	parsed_n = 0;
	i = -1;
	while (++i < cp->param_num)
	{
		param_byte = (int8_t *)(cp->param_value + i);
		param_byte += 4 - cp->param_size[i];
		j = -1;
		while (++j < cp->param_size[i])
		{
			*param_byte = (int8_t)cw->memory[(cp->pc + 2 + parsed_n) % MEM_SIZE];
			param_byte++;
			parsed_n++;
		}
	}
}

int8_t			process_ocp(t_cw *cw, t_process *cp, int8_t trunc)
{
	int8_t		i;
	int8_t		error;

	cp->ocp = cw->memory[(cp->pc + 1) % MEM_SIZE];
	cp->param_num = g_op_tab[cp->op].n_param;
	store_info_ocp(cp, cp->ocp, trunc);
	error = check_ocp_error(cp);
	// Add 2 because we need to add ocp and one more step to the next op
	cp->next_pc_distance += 2;
	if (error)
		return (1);
	// Get param value if there is no error
	get_param_value(cw, cp);
	i = -1;
	while (++i < cp->param_num)
		swap_32((uint32_t *)(cp->param_value + i));
	return (0);
}
