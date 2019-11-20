/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:50:19 by hypark            #+#    #+#             */
/*   Updated: 2019/11/13 11:35:31 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ----------------------------------------------------------------------------
** Function called to add new processes to list of processes.
**
** {t_cw *} cw - Main structure for corewar.
** {t_process *} cp - Process to be added to the list.
** ----------------------------------------------------------------------------
*/

void				process_add(t_cw *cw, t_process *cp)
{
	t_process		*process;

	process = cw->process_list;
	if (process == NULL)
		cw->process_list = cp;
	else
	{
		cp->next = process;
		cw->process_list = cp;
	}
}

/*
** ----------------------------------------------------------------------------
** This function is called whenever a process needs to be 'killed'. To do this
** since process is a node in a linked list of processes, we attach the node
** previous to the node we want to kill, to the node after it. Therefore, this
** process will not be checked any longer.
**
** {t_cw *} cw - Main structure for corewar.
** {t_process *} cp - Process being killed.
** ----------------------------------------------------------------------------
*/

static t_process	*process_kill(t_cw *cw, t_process *cp)
{
	t_process		*pre_node;

	if (cw->process_list == cp)
	{
		cw->process_list = cp->next;
		free(cp);
		PRO_DIED = 1;
		return (cw->process_list);
	}
	else
	{
		pre_node = cw->process_list;
		while (pre_node->next != cp)
			pre_node = pre_node->next;
		pre_node->next = cp->next;
		free(cp);
		PRO_DIED = 1;
		return (pre_node->next);
	}
}

/*
** ----------------------------------------------------------------------------
** This function is called at each 'CYCLE_TO_DIE' check. We go through the ll
** of processes and check for the process who didn't make a 'live' call then
** kill them.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

void				process_check_live(t_cw *cw)
{
	t_process		*cp;

	cp = cw->process_list;
	while (cp)
	{
		if (cp->live_call >= (CYCLE - KILL_CYCLE))
			cp = cp->next;
		else
			cp = process_kill(cw, cp);
	}
	if (cw->process_list == NULL)
		corewar_end(cw);
}

/*
** ----------------------------------------------------------------------------
** This function is called at each cycle of the vm, it goes through all the
** processes, verifies if the op code is valid, then applies the instruction
** of this op code if the timing is right.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

void				process_update(t_cw *cw)
{
	t_process		*cp;

	cp = cw->process_list;
	while (cp)
	{
		if (cp->op_called == 0)
		{
			cp->op = cw->memory[cp->pc] - 1;
			cp->op_called = 1;
		}
		if (cp->op <= 16 && cp->op >= 0)
		{
			if (CYCLE - cp->init_cycle == g_op_tab[cp->op].n_cycle)
				instruction_proceed(cw, cp);
		}
		else
		{
			cp->pc = (cp->pc + 1) % MEM_SIZE;
			cp->init_cycle = CYCLE;
			cp->op_called = 0;
		}
		cp = cp->next;
	}
}

/*
** ----------------------------------------------------------------------------
** This function is called to initialise new processes.
**
** {t_cw *} cw - Main structure for corewar.
** {t_champ *} id - Id of champion to whom the process being init 'belong' to.
** {uint16_t} pc - Current position of 'processor reader' in memory.
** ----------------------------------------------------------------------------
*/

t_process			*process_init(t_cw *cw, t_champ *id, uint16_t pc)
{
	t_process		*cp;

	if (!(cp = (t_process*)ft_memalloc(sizeof(t_process))))
		send_error("Error occured at process initializing\n");
	cp->pc = pc;
	cp->op = cw->memory[pc] - 1;
	cp->id = id;
	cp->registers[1] = (uint32_t)(id->prog_number * -1);
	cp->process_number = cw->process_index;
	cw->process_index++;
	cp->init_cycle = 0;
	cp->next = NULL;
	return (cp);
}
