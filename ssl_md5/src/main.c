/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:56:31 by hypark            #+#    #+#             */
/*   Updated: 2019/09/06 21:13:22 by hypark           ###   ########.fr       */
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

/*
** p_error("usage: ft_ssl command [command opts] [command args]");
*/

int					main(int ac, char **av)
{
	t_ssl			*ssl;

	!(ssl = init_ssl()) ? malloc_error("t_ssl") : 0;
	if (ac == 1)
		ssl->op |= OP_STDIN_CM;
	while (1)
	{
		ssl->op & OP_STDIN_CM ? stdin_ac_av(ssl, &ac, &av) : 0;
		if (ssl->op & OP_ERROR && free_av_ac(ssl, ac, av))
			continue ;
		mdc_command_check(ssl, av[1]) ? mdc_hash_size(ssl) : 0;
		if (ssl->mdc == -1)
			invalid_command(ssl, av[1]);
		if (ssl->op & OP_ERROR && free_av_ac(ssl, ac, av))
			continue ;
		mdc_read_input(ac, av, ssl);
		if (ssl->op & OP_ERROR && free_av_ac(ssl, ac, av))
			continue ;
		mdc_process(ssl);
		if ((ssl->op & OP_STDIN_CM) == 0)
			break ;
		free_av_ac(ssl, ac, av);
	}
	free_ssl(ssl);
	return (0);
}
