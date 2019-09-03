/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 00:49:51 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 01:34:13 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

/*
** p_op - print option
** 0 - default.
** if you want to add more options to print add functionality to this number
*/

void				cc_print_result(t_ssl *ssl, uint8_t p_op)
{
	uint32_t		i;

	i = 0;
	if (p_op != 0)
		p_error("You just enterted the wrong way");
	if (ssl->op & CC_O)
		write_file(ssl->cc_info->cc_write, ssl->cc_output, ssl->cc_len);
	else
	{
		while (i < ssl->cc_len)
			ft_printf("%c", ssl->cc_output[i++]);
	}
}
