/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 23:46:52 by hypark            #+#    #+#             */
/*   Updated: 2019/09/08 17:27:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

static char *g_cc_op[13] = {
	"-a", "-d", "-e", "-i", "-o",
	"-k", "-p", "-s", "-v", "-P",
	"-nosalt", "-nopad", NULL
};

/*
** Using ssl->op as a commonspace with mdc & cc so need to add
** (i + 4) because 4 places in the front of op is used by MDC
*/

/*
** Parse arguments if the option is
** -i -o -k -s -v
*/

static int8_t		cc_option_check(t_ssl *ssl, char *s)
{
	int8_t			i;

	i = -1;
	while (g_cc_op[++i] != NULL)
	{
		if (ft_strcmp(g_cc_op[i], s) == 0)
		{
			ssl->op |= 1 << (i + 4);
			if (i == 1)
				ssl->op &= ~(1 << 6);
			else if (i == 2)
				ssl->op &= ~(1 << 5);
			if (i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8)
				return (1);
			else
				return (0);
		}
	}
	cc_unknown_option(s);
	return (0);
}

static int8_t		cc_arg_parse(t_ssl *ssl, int ac, char **av, uint8_t i)
{
	if (i + 1 < ac)
	{
		if (ft_strcmp(av[i], "-i") == 0)
		{
			ssl->cc_info->cc_input = av[i + 1];
			ssl->total = 1;
		}
		else if (ft_strcmp(av[i], "-o") == 0)
			ssl->cc_info->cc_write = av[i + 1];
		else if (ft_strcmp(av[i], "-k") == 0)
			ssl->cc_info->cc_key = av[i + 1];
		else if (ft_strcmp(av[i], "-p") == 0)
			ssl->cc_info->cc_password = av[i + 1];
		else if (ft_strcmp(av[i], "-s") == 0)
			ssl->cc_info->cc_salt = av[i + 1];
		else if (ft_strcmp(av[i], "-v") == 0)
			ssl->cc_info->cc_iv = av[i + 1];
	}
	else
		cc_missing_arg_error(av[i]);
	return (i + 1);
}

/*
** input and output file only will be stored once
** renew everytime when it find a new input or output name
*/

void				cc_read_input(int ac, char **av, t_ssl *ssl)
{
	uint16_t		i;

	i = 1;
	if (!(ssl->cc_info = (t_cc *)ft_memalloc(sizeof(t_cc))))
		malloc_error("t_cc");
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (cc_option_check(ssl, av[i]))
				i = cc_arg_parse(ssl, ac, av, i);
		}
		else
			cc_usage_error();
	}
	if (!(ssl->op & CC_E) && !(ssl->op & CC_D))
		ssl->op |= CC_E;
	if (ssl->total == 0)
		ssl->p_stdin = 1;
}
