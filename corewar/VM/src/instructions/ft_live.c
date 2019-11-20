/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:30:44 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/13 22:07:37 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_live(t_cw *cw, t_process *cp)
{
	int32_t			prog_num;
	uint8_t			*param_byte;
	int8_t			i;

	cw->n_live_call += 1;
	param_byte = (uint8_t *)(&prog_num);
	i = -1;
	while (++i < 4)
	{
		*param_byte = cw->memory[(cp->pc + 1 + i) % MEM_SIZE];
		param_byte++;
	}
	swap_int32(&prog_num);
	prog_num *= -1;
	if (prog_num >= 1 && prog_num <= MAX_PLAYERS)
		cw->winner = &CHAMP(prog_num - 1);
	cp->live_call = CYCLE;
	FLAG & FL_VER4 ? ft_printf("P%5d | live %d\n", P_I, -1 * prog_num) : 0;
}
