/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:59:11 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 19:09:45 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

char *g_mdc_prefix[3] = {"MD5", "SHA256", NULL};

/*
** print option -> p_op
** 0 - no suffix or prefix - NO MD5 X
** 1 - suffix or prefix should be surrounded by MD5i ("string")
** 2 - printout normally with file name without MD5 (file.txt)
*/

static void			mdc_print_hash(t_ssl *ssl)
{
	int8_t			i;

	i = -1;
	if (ssl->mdc == 0)
		while (++i < ssl->hash_size)
			ft_printf("%08x", swap_endian32(ssl->hash_output[i]));
	if (ssl->mdc == 1)
		while (++i < ssl->hash_size)
			ft_printf("%08x", ssl->hash_output[i]);
}

static void			mdc_print_prefix(t_ssl *ssl, uint8_t p_op)
{
	ft_printf("%s (", g_mdc_prefix[ssl->mdc]);
	if (p_op == 1)
		ft_printf("\"%s\"", ssl->ssl_input);
	else if (p_op == 2)
		ft_printf("%s", ssl->files[ssl->i]);
	ft_printf(") = ");
}

static void			mdc_print_suffix(t_ssl *ssl, uint8_t p_op)
{
	ft_putchar(' ');
	if (p_op == 1)
		ft_printf("\"%s\"", ssl->ssl_input);
	else if (p_op == 2)
		ft_printf("%s", ssl->files[ssl->i]);
}

void				mdc_print_result(t_ssl *ssl, uint8_t p_op)
{
	if (!(ssl->op & OP_Q) && !(ssl->op & OP_R) && p_op != 0)
		mdc_print_prefix(ssl, p_op);
	mdc_print_hash(ssl);
	if (!(ssl->op & OP_Q) && ssl->op & OP_R && p_op != 0)
		mdc_print_suffix(ssl, p_op);
	ft_putchar('\n');
}
