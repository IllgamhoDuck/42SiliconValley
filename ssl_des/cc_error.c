/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:45:44 by hypark            #+#    #+#             */
/*   Updated: 2019/08/27 00:53:46 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"

void				cc_missing_arg_error(char *op)
{
	ft_printf("missing ");
	ft_strcmp(op, "-i") == 0 ? ft_printf("file") : 0;
	ft_strcmp(op, "-o") == 0 ? ft_printf("file") : 0;
	ft_strcmp(op, "-k") == 0 ? ft_printf("Key") : 0;
	ft_strcmp(op, "-s") == 0 ? ft_printf("salt") : 0;
	ft_strcmp(op, "-v") == 0 ? ft_printf("IV") : 0;
	ft_printf(" argument for %s\n", op);
	cc_usage_error();
}

void				cc_unknown_option(char *op)
{
	ft_printf("unknown option '%s'\n", op);
	cc_usage_error();
}

void				cc_usage_error(void)
{
	ft_printf("usage: enc -ciphername n");
	ft_printf("[-ade] [-i in_file] [-o out_file] [-k key]\n");
	ft_printf("[-p password] [-s salt] [-v IV]\n\n");
	ft_printf("%7s decode/encode the input/output in base64, ", "-a");
	ft_printf("depending on the encrypt mode\n");
	ft_printf("%7s decrypt mode\n", "-d");
	ft_printf("%7s encrypt mode (default)\n", "-e");
	ft_printf("%7s input file for message\n", "-i");
	ft_printf("%7s output file for message\n", "-o");
	ft_printf("%7s key in hex is the next arguement\n", "-k");
	ft_printf("%7s password in ascii is the next argument\n", "-p");
	ft_printf("%7s the salt in hex is the next argument\n", "-s");
	ft_printf("%7s initialization vector in hex is the next argument\n", "-v");
	exit(1);
}
