/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:46:45 by hypark            #+#    #+#             */
/*   Updated: 2019/10/22 22:43:52 by hypark           ###   ########.fr       */
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
	ft_printf("player %d called live\n", -1 * prog_num);
	if (prog_num == -1)
		cw->winner = &CHAMP(0);
	else if (prog_num == -2)
		cw->winner = &CHAMP(1);
	else if (prog_num == -3)
		cw->winner = &CHAMP(2);
	else if (prog_num == -4)
		cw->winner = &CHAMP(3);
	else
		cw->n_live_call -= 1;
    cp->live_call = cw->cycle.cycle;
}
