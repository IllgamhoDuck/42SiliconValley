/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:03:04 by hypark            #+#    #+#             */
/*   Updated: 2019/09/06 12:53:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void				s_usage_error(t_ssl *ssl)
{
	if (ssl->mdc != -1)
		ft_printf("%2@%s: ", g_md_command[ssl->mdc]);
	ft_printf("%2@option requires an argument -- s\n");
	if (ssl->mdc != -1)
		ft_printf("%2@usage: %s ", g_md_command[ssl->mdc]);
	ft_printf("%2@[-pqrtx] [-s string] [files ...]\n");
	ssl->op |= OP_ERROR;
	ssl->op & OP_STDIN_CM ? 0 : exit(1);
}

void				p_error_ssl(t_ssl *ssl, char *str)
{
	perror(str);
	ssl->op |= OP_ERROR;
	ssl->op & OP_STDIN_CM ? 0 : exit(1);
}
