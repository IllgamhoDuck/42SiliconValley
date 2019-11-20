/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:50:18 by hypark            #+#    #+#             */
/*   Updated: 2019/11/16 09:28:33 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ----------------------------------------------------------------------------
** Function used to end the game and print the winner on the stdout.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

void				corewar_end(t_cw *cw)
{
	if (GUI)
		endwin();
	ft_printf("Contestant %d", WINNER->prog_number);
	ft_printf(", \"%s\", has won !\n", WINNER->name);
	exit(0);
}

/*
** ----------------------------------------------------------------------------
** Function used to check all rules for the game to stay active. I'm too lazy to
** list them all.. maybe later.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

static void			cycle_check(t_cw *cw)
{
	if (CYCLE_TMP == KILL_CYCLE)
	{
		if ((cw->n_live_call >= NBR_LIVE && PRO_DIED == 0)
		|| (KC_CHECK == MAX_CHECKS))
		{
			KILL_CYCLE -= CYCLE_DELTA;
			KC_CHECK = 1;
		}
		else
			KC_CHECK += 1;
		process_check_live(cw);
		cw->n_live_call = 0;
		CYCLE_TMP = 0;
		PRO_DIED = 0;
	}
	if (KILL_CYCLE <= 0)
		KILL_CYCLE = 1;
}

/*
** ----------------------------------------------------------------------------
** Function used to introduce all existing champions if there's no GUI.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

static void			player_intro(t_cw *cw)
{
	int				i;
	t_champ			cc;

	i = -1;
	write(1, "Introducing contestants...\n", 27);
	while (++i < cw->n_players)
	{
		cc = CHAMP(i);
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",\
		cc.prog_number, cc.prog_size, cc.name, cc.comment);
	}
}

/*
** ----------------------------------------------------------------------------
** Function that runs the vm, and end it at an appropriate time. Can init
** the GUI if requested and update the content at each cycle. This function
** calls all function required to manipulate virtual memory and handle end of
** game.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

void				corewar_run(t_cw *cw)
{
	if (GUI)
		gui_init(cw);
	else
		player_intro(cw);
	while (1)
	{
		process_update(cw);
		cycle_check(cw);
		if (GUI)
			gui_update(cw);
		if (DUMP && CYCLE == DUMP_CYCLE)
			dump_memory(cw);
		++CYCLE;
		++CYCLE_TMP;
	}
	if (GUI)
		endwin();
	exit(1);
}
