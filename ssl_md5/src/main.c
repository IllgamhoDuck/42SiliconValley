/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:56:31 by hypark            #+#    #+#             */
/*   Updated: 2019/08/26 00:45:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

static uint8_t		mdc_command_check(t_ssl *ssl, char *s)
{
	int16_t			i;

	i = -1;
	while (g_md_command[++i] != NULL)
	{
		if (ft_strcmp(g_md_command[i], s) == 0)
		{
			ssl->mdc = i;
			return (1);
		}
	}
	return (0);
}

int					main(int ac, char **av)
{
	t_ssl			*ssl;

	if (ac == 1)
		p_error("usage: ft_ssl command [command opts] [command args]");
	!(ssl = init_ssl()) ? malloc_error("t_ssl") : 0;
	mdc_command_check(ssl, av[1]) ? mdc_hash_size(ssl) : 0;
	if (ssl->mdc == -1)
		invalid_command(av[1]);
	if (ssl->mdc != -1)
	{
		mdc_read_input(ac, av, ssl);
		mdc_process(ssl);
	}
	free_ssl(ssl);
	return (0);
}
