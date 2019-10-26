/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:44:30 by hypark            #+#    #+#             */
/*   Updated: 2019/10/25 22:26:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_zjump(t_cw *cw, t_process *cp)
{
	int16_t			offset;
	int32_t			test;

	offset = (int16_t)cp->param_value[0];
    if (cp->carry == 1)
	{
		if (cp->param_type[0] == T_DIR)
			cp->pc = pc_idx_mod(cp, offset);
		FLAG & FL_VER4 ? ft_printf("P%5d | ", P_I) : 0;
		FLAG & FL_VER4 ? ft_printf("zjmp %d OK\n", offset) : 0;
	}
}
