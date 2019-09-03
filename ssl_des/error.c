/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:11:57 by hypark            #+#    #+#             */
/*   Updated: 2019/09/03 00:17:51 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void				invalid_command(char *command)
{
	int8_t			i;

	ft_printf("%2@openssl:Error: '%s' is an invalid command.\n\n", command);
	ft_printf("%2@Standard commands:\n");
	ft_printf("%2@\n");
	ft_printf("%2@Message Digest commands:\n");
	i = -1;
	while (++i < 7)
		ft_printf("%2@%s\n", g_md_command[i]);
	ft_printf("%2@\n");
	ft_printf("%2@Cipher commands:\n");
	i = -1;
	while (++i < 1)
		ft_printf("%2@%s\n", g_c_command[i]);
	exit(1);
}

void				no_file_dic(t_ssl *ssl)
{
	if (ssl->mdc != -1)
		ft_printf("%2@%s: ", g_md_command[ssl->mdc]);
	if (ssl->cc != -1)
		ft_printf("%2@%s: ", g_c_command[ssl->cc]);
	if (ssl->mdc != -1)
		ft_printf("%2@%s: No such file or directory\n", ssl->files[ssl->i]);
	if (ssl->cc != -1)
	{
		ft_printf("%2@%s: ", ssl->cc_info->cc_input);
		ft_printf("%2@No such file or directory\n");
	}
}

void				malloc_error(char *str)
{
	ft_printf("%2@Memory Allocation Failed at %s\n", str);
	exit(1);
}

void				p_error(char *str)
{
	perror(str);
	exit(1);
}
