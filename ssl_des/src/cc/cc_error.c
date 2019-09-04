/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:45:44 by hypark            #+#    #+#             */
/*   Updated: 2019/08/29 15:31:59 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"

void				cc_missing_arg_error(char *op)
{
	ft_printf("%2@missing ");
	ft_strcmp(op, "-i") == 0 ? ft_printf("%2@file") : 0;
	ft_strcmp(op, "-o") == 0 ? ft_printf("%2@file") : 0;
	ft_strcmp(op, "-k") == 0 ? ft_printf("%2@key") : 0;
	ft_strcmp(op, "-p") == 0 ? ft_printf("%2@source") : 0;
	ft_strcmp(op, "-s") == 0 ? ft_printf("%2@salt") : 0;
	ft_strcmp(op, "-v") == 0 ? ft_printf("%2@IV") : 0;
	ft_printf("%2@ argument for %s\n", op);
	cc_usage_error();
}

void				cc_unknown_option(char *op)
{
	ft_printf("%2@unknown option '%s'\n", op);
	cc_usage_error();
}

void				cc_usage_error(void)
{
	ft_printf("%2@usage: enc -ciphername n ");
	ft_printf("%2@[-ade] [-i in_file] [-o out_file] [-k key]\n");
	ft_printf("%2@                         ");
	ft_printf("%2@[-p password] [-s salt] [-v IV]\n\n");
	ft_printf("%2@%-3s decode/encode the input/output in base64, ", "-a");
	ft_printf("%2@depending on the encrypt mode\n");
	ft_printf("%2@%-3s decrypt mode\n", "-d");
	ft_printf("%2@%-3s encrypt mode (default)\n", "-e");
	ft_printf("%2@%-3s input file for message\n", "-i");
	ft_printf("%2@%-3s output file for message\n", "-o");
	ft_printf("%2@%-3s key in hex is the next arguement\n", "-k");
	ft_printf("%2@%-3s password in ascii is the next argument\n", "-p");
	ft_printf("%2@%-3s the salt in hex is the next argument\n", "-s");
	ft_printf("%2@%-3s initialization vector in hex ", "-v");
	ft_printf("%2@is the next argument\n");
	exit(1);
}
