/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:48:34 by hypark            #+#    #+#             */
/*   Updated: 2019/10/24 20:37:53 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

static t_process	*process_copy(t_cw *cw, t_process *copy_cp, int16_t pc)
{
	t_process		*cp;
	int8_t			i;

	if (!(cp = (t_process*)ft_memalloc(sizeof(t_process))))
		send_error("Error occured at process initializing\n");
	cp->pc = pc;
	cp->op = 'X';
	cp->id = copy_cp->id;
	i = 0;
	while (++i <= REG_NUMBER)
		cp->registers[i] = copy_cp->registers[i];
	cp->init_cycle = cw->cycle.cycle;
	cp->next = NULL;
	cp->live_call = copy_cp->live_call;
	++cw->n_process;
	return (cp);
}

void				ft_fork(t_cw *cw, t_process *cp)
{
	int16_t			address;
	int32_t			param;
	int8_t			*param_byte;

	if (cp->param_type[0] == T_DIR)
	{
		param_byte = (int8_t *)&param;
		address = (int16_t)cp->param_value[0];
		FLAG & FL_VER4 ? ft_printf("fork %d ", address) : 0;
		address = pc_idx_mod(cp, address);
		FLAG & FL_VER4 ? ft_printf("(%d)\n", address) : 0;
		process_add(cw, process_copy(cw, cp, address));
	}
}
