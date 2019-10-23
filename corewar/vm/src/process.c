/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:50:19 by hypark            #+#    #+#             */
/*   Updated: 2019/10/22 23:28:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				process_add(t_cw *cw, t_process *cp)
{
	t_process		*process;

	process = cw->process_list;
	if (process == NULL)
		cw->process_list = cp;
	else
	{
		while (process->next)
			process = process->next;
		process->next = cp;
	}
}

static void			process_kill(t_cw *cw, t_process *cp)
{
	t_process		*pre_node;

	cw->n_process--;
	// if the deleting processor is the first one
	if (cw->process_list == cp)
	{
		cw->process_list = cp->next;
		free(cp);
	}
	else
	{
		// if the deleting processor is the not the first one
		pre_node = cw->process_list;
		while (pre_node->next != cp)
			pre_node = pre_node->next;
		pre_node->next = cp->next;
		free(cp);
	}
}

void			process_check_live(t_cw *cw)
{
	t_process	*cp;

	cp = cw->process_list;
	while (cp)
	{
		if ((cp->live_call >= (CYCLE - KILL_CYCLE)) == 0)
			process_kill(cw, cp);
		cp = cp->next;
	}
	// if there is no processor live then end the corewar
	if (cw->process_list == NULL)
		corewar_end(cw);
}

void       		 process_update(t_cw *cw)
{
	t_process   *cp;

	cp = cw->process_list;
	while (cp)
	{
		if (cp->op < 16)
		{
			if (CYCLE - cp->init_cycle == g_op_tab[cp->op].n_cycle)
				instruction_proceed(cw, cp);
		}
		else if (cw->memory[cp->pc] <= 16 && cw->memory[cp->pc])
		{
			cp->op = cw->memory[cp->pc] - 1;
			cp->init_cycle = CYCLE;
		}
		else
			cp->pc = (cp->pc + 1) % MEM_SIZE;
		cp = cp->next;
	}
}


t_process       *process_init(t_cw *cw, t_champ *id, uint16_t pc)
{
	t_process   *cp;
	uint32_t	big_endian_name;

	if (!(cp = (t_process*)ft_memalloc(sizeof(t_process))))
		send_error("Error occured at process initializing\n");
	cp->pc = pc;
	cp->op = cw->memory[pc] - 1;
	cp->id = id;
	big_endian_name = (uint32_t)(id->prog_number * -1);
	swap_32(&big_endian_name);
	cp->registers[1] = big_endian_name;
	++cw->n_process;
	cp->init_cycle = 0;
	cp->next = NULL;
	return (cp);
}
