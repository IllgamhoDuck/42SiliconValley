/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:46:48 by hypark            #+#    #+#             */
/*   Updated: 2019/11/13 22:07:37 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_aff(t_cw *cw, t_process *cp)
{
	int8_t			ascii;

	if (FLAG & FL_A)
	{
		ascii = (int8_t)(cp->registers[cp->param_value[0]] % 256);
		ft_printf("%c", ascii);
	}
}
