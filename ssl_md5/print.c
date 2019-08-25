/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 23:09:36 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 01:32:35 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "libft.h"

/*
** print option -> p_op
** 0 - no suffix or prefix - NO MD5 X
** 1 - suffix or prefix should be surrounded by MD5("string")
** 2 - printout normally with file name without MD5(file.txt)
*/

void				print_hash(t_ssl *ssl, uint8_t p_op)
{
	int8_t			i;

	i = -1;
	if (!(ssl->op & OP_Q))
		//printout the hash;
	while (++i < ssl->hash_size)
		ft_printf("%08x", swap_endian32(ssl->hash_output[i]));
	ft_putchar('\n');
}
