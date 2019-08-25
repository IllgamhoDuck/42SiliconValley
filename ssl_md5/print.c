/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 23:09:36 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 16:10:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"
#include "libft.h"

char *g_mdc_prefix[3] = {"MD5", "SHA256", NULL};

/*
** print option -> p_op
** 0 - no suffix or prefix - NO MD5 X
** 1 - suffix or prefix should be surrounded by MD5i ("string")
** 2 - printout normally with file name without MD5 (file.txt)
*/

static void			print_hash(t_ssl *ssl)
{
	int8_t			i;

	i = -1;
	while (++i < ssl->hash_size)
		ft_printf("%08x", swap_endian32(ssl->hash_output[i]));
}

static void			print_prefix(t_ssl *ssl, uint8_t p_op)
{
	ft_printf("%s (", g_mdc_prefix[ssl->mdc]);
	if (p_op == 1)
		ft_printf("\"%s\"", ssl->hash_input);
	else if (p_op == 2)
		ft_printf("%s", ssl->files[ssl->i]);
	ft_printf(") = ");
}

static void			print_suffix(t_ssl *ssl, uint8_t p_op)
{
	ft_putchar(' ');
	if (p_op == 1)
		ft_printf("\"%s\"", ssl->hash_input);
	else if (p_op == 2)
		ft_printf("%s", ssl->files[ssl->i]);
}

void				print_result(t_ssl *ssl, uint8_t p_op)
{
	if (!(ssl->op & OP_Q) && !(ssl->op & OP_R) && p_op != 0)
		print_prefix(ssl, p_op);
	print_hash(ssl);
	if (!(ssl->op & OP_Q) && ssl->op & OP_R && p_op != 0)
		print_suffix(ssl, p_op);
	ft_putchar('\n');
}
