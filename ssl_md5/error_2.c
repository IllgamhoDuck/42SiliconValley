/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:03:04 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 23:44:45 by hypark           ###   ########.fr       */
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
	exit(1);
}
