/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:11:57 by hypark            #+#    #+#             */
/*   Updated: 2019/08/22 17:34:33 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void				invalid_command(char *command)
{
	uint8_t			i;

	ft_printf("%2@openssl:Error: '%s' is an invalid command.\n\n", command);
	ft_printf("Standard commands\n");
	i = 0;
	// while all
	ft_printf("\n");
	ft_printf("Message Digest commands\n");
	i = 0;
	// while all
	ft_printf("\n");
	ft_printf("Cipher commands\n");
	i = 0;
	// while all
}

void				unknown_option(char *op)
{
	ft_printf("%2@unknown option '%s'\n", op);
	ft_printf("%2@options are\n");
	ft_printf("%2@-p  echo STDIN to STDOUT and append the checksum to STDOUT");
	ft_printf("%2@-q  quiet mode");
	ft_printf("%2@-r  reverse the format of the output");
	ft_printf("%2@-s  print the sum of the given string");
	exit(1);
}

void				no_file_dic(char *file)
{
	ft_printf("%2@ls: %s: No such file or directory\n", file);
}

void				malloc_error(char *str)
{
	ft_printf("%2@Memory Allocation Failed at %s\n", str);
	exit(1);
}

void				p_error(char *str)
{
	ft_printf("%2@%s\n", str);
	exit(1);
}
