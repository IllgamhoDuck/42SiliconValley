/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:46:45 by hypark            #+#    #+#             */
/*   Updated: 2019/10/25 11:26:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_live(t_cw *cw, t_process *cp)
{
    uint32_t		prog_num;
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
    swap_32(&prog_num);
	if (prog_num <= -1 && prog_num >= -4)
		cw->winner = &CHAMP((prog_num * -1) - 1);
	else
		cw->n_live_call -= 1;
    cp->live_call = cw->cycle.cycle;
	FLAG & FL_VER4 ? ft_printf("P%5d | live %d\n", P_I, prog_num) : 0;
}
