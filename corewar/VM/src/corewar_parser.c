/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:18:53 by hypark            #+#    #+#             */
/*   Updated: 2019/11/15 21:36:55 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ----------------------------------------------------------------------------
** Function that handles the '-d' flag and assigns a dump_cycle at av[dump_arg]
** cycle.
**
** {t_cw *} cw - Main structure for corewar.
** {int} dump_arg - Index of argument containing the dump_cycle.
** ----------------------------------------------------------------------------
*/

static void			parse_dump_number(t_cw *cw, int dump_arg)
{
	if (dump_arg < AC)
	{
		FLAG |= FL_DUMP;
		DUMP_CYCLE = ft_stoi(AV[dump_arg]);
	}
	else
		send_error("Missing dump cycle number.\n");
}

/*
** ----------------------------------------------------------------------------
** Function that handles the '-n' flag and assigns a fixed prog_number to
** a champion and verifies that the number given is valid.
**
** {t_cw *} cw - Main structure for corewar.
** {int} num - 	Index of argument containing the requested prog_number for
**				next loaded champion.
** {int} champ_arg - Index of argument the champion to be loaded next.
** ----------------------------------------------------------------------------
*/

static void			parse_prog_number(t_cw *cw, int num, int champ_arg)
{
	int				prog_num;

	if (num < AC)
	{
		prog_num = ft_stoi(AV[num]);
		if (prog_num > cw->n_players || prog_num <= 0)
			send_error("Program number must be between 1 and MAX_PLAYERS\n");
		if (CHAMP(prog_num - 1).manual_assign == 1)
			send_error("Player has already been assigned to this number.\n");
		CHAMP(prog_num - 1).manual_assign = 1;
		champ_load(cw, AV[champ_arg], prog_num - 1);
	}
	else
		send_error("Missing program number.\n");
}

/*
** ----------------------------------------------------------------------------
** Parse the potential flag (arg starting with '-'), check its validity
** and apply it if valid.
**
** {t_cw *} cw - Main structure for corewar.
** {int *} curr_arg - Pointer to index of flag to be analysed (av[curr_arg]).
** ----------------------------------------------------------------------------
*/

static void			parse_verbose_number(t_cw *cw, int verbose_arg)
{
	int				verbose;

	if (verbose_arg < AC)
	{
		verbose = ft_stoi(AV[verbose_arg]);
		verbose == 0 ? FLAG |= FL_VER0 : 0;
		verbose == 1 ? FLAG |= FL_VER1 : 0;
		verbose == 2 ? FLAG |= FL_VER2 : 0;
		verbose == 4 ? FLAG |= FL_VER4 : 0;
		verbose == 8 ? FLAG |= FL_VER8 : 0;
		verbose == 16 ? FLAG |= FL_VER16 : 0;
	}
	else
		send_error("Missing verbose number.\n");
}

static void			parse_flag(t_cw *cw, int *curr_arg)
{
	if (ft_strlen(AV[*curr_arg]) != 2)
		send_error("Incorrect flag.\n");
	AV[*curr_arg]++;
	if (*AV[*curr_arg] == 'd')
		parse_dump_number(cw, ++(*curr_arg));
	else if (*AV[*curr_arg] == 'v')
		parse_verbose_number(cw, ++(*curr_arg));
	else if (*AV[*curr_arg] == 'g')
		FLAG |= FL_GUI;
	else if (*AV[*curr_arg] == 'a')
		FLAG |= FL_A;
	else if (*AV[*curr_arg] == 'n' && (*curr_arg) + 2 < AC)
		parse_prog_number(cw, ++(*curr_arg), ++(*curr_arg));
	else
		send_error("Incorrect flag.\n");
}

/*
** ----------------------------------------------------------------------------
** Main command line parsing function that will parse command line and check
** for any potential errors that might lead to uncatched errors and stores
** all important informations.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

void				corewar_parser(t_cw *cw)
{
	int32_t			i;

	i = -1;
	while (++i < cw->n_players)
	{
		CHAMP(i).manual_assign = 0;
		cw->tmp_champ[i].manual_assign = 0;
	}
	i = -1;
	while (++i < AC)
	{
		if (AV[i][0] == '-')
			parse_flag(cw, &i);
		else
			champ_load(cw, AV[i], -1);
	}
	champ_assign(cw);
}
