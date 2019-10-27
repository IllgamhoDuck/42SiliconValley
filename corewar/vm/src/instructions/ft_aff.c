/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:46:48 by hypark            #+#    #+#             */
/*   Updated: 2019/10/26 22:58:54 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ft_aff(t_cw *cw, t_process *cp)
{
	int32_t			ascii;

	ascii = cp->registers[cp->param_value[0]] % 256;
	if (ascii)
		cp->carry = 1;
	else
		cp->carry = 0;
    ft_printf("%c", ascii);
}
