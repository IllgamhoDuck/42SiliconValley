#include "vm.h"

//static void			process_kill(t_cw *cw, int kill_node)
//{
//	int			i;
//	t_process	**kp;
//
//	i = -1;
//	kp = &(cw->process_list);
//	if (kill_node == 0 && cw->n_process <= 1)
//		*kp = NULL;
//	else if (kill_node == 0 && cw->n_process > 1)
//		*kp = (*kp)->next;
//	else
//	{
//		while (++i < kill_node - 1)
//			(*kp) = (*kp)->next;
//		(*kp)->next = (*kp)->next->next;
//	}
//	cw->n_process--;
//	cw->n_live_call = 0;
//}
//void			process_check_live(t_cw *cw)
//{
//	t_process	*cp;
//	int			kill_node;
//
//	kill_node = 0;
//	cp = cw->process_list;
//	while (cp)
//	{
//		if (cp->live_call >= (CYCLE - KILL_CYCLE))
//			++kill_node;
//		else
//			process_kill(cw, kill_node);
//		cp = cp->next;
//	}
//	// move it down here antoine.
//	if (cp == NULL)
//		corewar_end(cw);
//}

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
	int			kill_node;
 (cp->op <= 17)
//  while (acb)                                                                                           |    uint32_t        registers[REG_NUMBER + 1];                                                           |        {
//  {                                                                                                     |    t_champ         *id;                                                                                 |            if (CYCLE - cp->init_cycle == g_op_tab[cp->op].n_cycle)
//      if (g_op_tab[cp->op].trunc == 1)                                                                  |    struct s_process *next;                                                                              |                instru
	kill_node = 0;
	cp = cw->process_list;
	while (cp)
	{
		if (cp->live_call >= (CYCLE - KILL_CYCLE))
			cp = cp->next;
		else
			process_kill(cw, cp);
	}
	// if there is no processor live then end the corewar
	if (cw->process_list == NULL)
		corewar_end(cw);
}

/*
** ----------------------------------------------------------------------------
** Function used to go through all of the currently running programs, check
** the ones who need to be executed at this cycle and jump their pc to the
** next instruction's opcode in memory.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

void        process_update(t_cw *cw)
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
		else if (cw->memory[cp->pc] <= 16)
		{
			cp->op = cw->memory[cp->pc] - 1;
			cp->init_cycle = CYCLE;
		}
		else
			cp->pc = (cp->pc + 1) % MEM_SIZE;
		cp = cp->next;
	}
}

/*
** ----------------------------------------------------------------------------
** Function used to check all rules for the game to stay active. I'm too lazy to
** list them all.. maybe later.
**
** {t_cw *} cw - Main structure for corewar.
** {t_champ *} id - Champion to whom this new process belongs to.
** {void *} - Pointer to first begining of instruction in memory.
** ----------------------------------------------------------------------------
*/

void        process_init(t_cw *cw, t_champ *id, uint16_t pc)
{
	t_process   *cp;
	t_process   **list;

	list = &cw->process_list;
	if (!(cp = (t_process*)ft_memalloc(sizeof(t_process))))
		return ;
	cp->pc = pc;
	cp->op = cw->memory[pc] - 1;
	cp->id = id;
	cp->registers[1] = (uint32_t)(id->prog_number);
	++cw->n_process;
	// changed init cycle 1 -> 0
	cp->init_cycle = 0;
	cp->next = *list;
	*list = cp;
}
