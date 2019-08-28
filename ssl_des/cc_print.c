/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 00:49:51 by hypark            #+#    #+#             */
/*   Updated: 2019/08/28 01:41:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

/*
** p_op - print option
** 0 - default.
** if you want to add more options to print add functionality to this number
*/

//static void			cc_print_key(t_ssl *ssl)
//{
//	int8_t			i;
//
//	i = -1;
//	if (ssl->cc == 0 && ssl->cc_output != NULL)
//		while (++i < ssl->hash_size)
//			ft_printf("%016llx", ssl->hash_output64[i]);
//}

void				cc_print_result(t_ssl *ssl, uint8_t p_op)
{
	if (p_op != 0)
		p_error("You just enterted the wrong way");
	if (ssl->op & CC_O)
		write_file(ssl->cc_info->cc_write, ssl->cc_output);
	else
		ft_printf("%s", ssl->cc_output);
}
