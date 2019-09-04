/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:56:31 by hypark            #+#    #+#             */
/*   Updated: 2019/09/04 05:12:33 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

static uint8_t		mdc_command_check(t_ssl *ssl, char *cmd)
{
	int16_t			i;

	i = -1;
	while (g_md_command[++i] != NULL)
	{
		if (ft_strcmp(g_md_command[i], cmd) == 0)
		{
			ssl->mdc = i;
			return (1);
		}
	}
	return (0);
}

/*
** des is a abbreviatiion of des-cbc
** des3 is a abbreviatiion of des3-cbc
*/

static uint8_t		cc_command_check(t_ssl *ssl, char *cmd)
{
	int16_t			i;

	i = -1;
	while (g_c_command[++i] != NULL)
	{
		if (ft_strcmp(g_c_command[i], cmd) == 0)
		{
			ssl->cc = i;
			i == 1 ? ssl->cc = 3 : 0;
			i == 6 ? ssl->cc = 8 : 0;
			return (1);
		}
	}
	return (0);
}

static void			process_ssl(int ac, char **av, t_ssl *ssl)
{
	if (ssl->mdc != -1)
	{
		mdc_read_input(ac, av, ssl);
		mdc_process(ssl);
	}
	else if (ssl->cc != -1)
	{
		cc_read_input(ac, av, ssl);
		cc_process(ssl);
	}
}

int					main(int ac, char **av)
{
	t_ssl			*ssl;

	if (ac == 1)
		p_error("usage: ft_ssl command [command opts] [command args]");
	!(ssl = init_ssl()) ? malloc_error("t_ssl") : 0;
	mdc_command_check(ssl, av[1]) ? mdc_hash_size(ssl) : 0;
	cc_command_check(ssl, av[1]) ? mdc_hash_size(ssl) : 0;
	if (ssl->mdc == -1 && ssl->cc == -1)
		invalid_command(av[1]);
	process_ssl(ac, av, ssl);
	free_ssl(ssl);
	return (0);
}
