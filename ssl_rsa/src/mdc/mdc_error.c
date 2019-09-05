/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdc_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:38:41 by hypark            #+#    #+#             */
/*   Updated: 2019/08/26 22:39:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void				mdc_unknown_option(char *op)
{
	ft_printf("%2@unknown option '%s'\n", &op[1]);
	ft_printf("%2@options are\n");
	ft_printf("%2@-p  echo STDIN to STDOUT ");
	ft_printf("%2@and append the checksum to STDOUT\n");
	ft_printf("%2@-q  quiet mode\n");
	ft_printf("%2@-r  reverse the format of the output\n");
	ft_printf("%2@-s  print the sum of the given string\n");
	exit(1);
}

void				mdc_s_usage_error(t_ssl *ssl)
{
	if (ssl->mdc != -1)
		ft_printf("%2@%s: ", g_md_command[ssl->mdc]);
	ft_printf("%2@option requires an argument -- s\n");
	if (ssl->mdc != -1)
		ft_printf("%2@usage: %s ", g_md_command[ssl->mdc]);
	ft_printf("%2@[-pqrtx] [-s string] [files ...]\n");
	exit(1);
}
