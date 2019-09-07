/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:11:57 by hypark            #+#    #+#             */
/*   Updated: 2019/09/06 12:53:33 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void				invalid_command(t_ssl *ssl, char *command)
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
	ssl->op |= OP_ERROR;
	ssl->op & OP_STDIN_CM ? 0 : exit(1);
}

void				unknown_option(t_ssl *ssl, char *op)
{
	ft_printf("%2@unknown option '%s'\n", &op[1]);
	ft_printf("%2@options are\n");
	ft_printf("%2@-p  echo STDIN to STDOUT ");
	ft_printf("%2@and append the checksum to STDOUT\n");
	ft_printf("%2@-q  quiet mode\n");
	ft_printf("%2@-r  reverse the format of the output\n");
	ft_printf("%2@-s  print the sum of the given string\n");
	ssl->op |= OP_ERROR;
	ssl->op & OP_STDIN_CM ? 0 : exit(1);
}

void				no_file_dic(t_ssl *ssl)
{
	if (ssl->mdc != -1)
		ft_printf("%2@%s: ", g_md_command[ssl->mdc]);
	ft_printf("%2@%s: No such file or directory\n", ssl->files[ssl->i]);
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
