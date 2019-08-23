/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:59:29 by hypark            #+#    #+#             */
/*   Updated: 2019/08/23 13:04:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

static void			command_check(t_ssl *ssl, char *s)
{
	int8_t			i;

	i = -1;
	while (g_mdc[++i] != NULL)
	{
		if (ft_strcmp(g_mdc[i], s) == 0)
		{
			ssl->mdc |= 1 << i;
			return ;
		}
	}
	invalid_command(av[i]);
}

/*
** Reverses the format of the	output.	 This helps with visual	diffs.
** Does nothing when combined	with the -ptx options.
** i == 0  means option -p
** ssl->op &= ~OF_R;
*/

static void			option_check(t_ssl *ssl, char *s)
{
	int8_t			i;

	i = -1;
	while (g_op[++i] != NULL)
	{
		if (ft_strcmp(g_op[i], s) == 0)
		{
			if (i == 0)
				ssl->op &= ~OF_R;
			ssl->op |= 1 << i;
			return ;
		}
	}
	unknown_option(av[i]);
}

/*
** input_checker checks the input is valid and store the information
** If there is no files at main parameter the stdin will be used
** t_reader is for standard input fd = 0
** if no main parameter than start stdin 
** if -p option is here than parse the standard input
** original md5 stops when -p and no stdin
*/

void				read_input(int ac, char **av, t_ssl *ssl)
{
	uint8_t			i;

	i = 0;
	while (++i < ac)
	{
		if (i == 1)
			command_check(ssl, av[i]);
		if (av[i][0] == '-')
			option_check(ssl, av[i]);
		else
		{
			if (!(ssl->file = (char **)malloc(sizeof(char *) * ac - i + 1)))
				malloc_error("ssl->file");
			while (i < ac)
				ssl->file[ssl->total++] = av[i++];
			ssl->file[ssl->total] = NULL;
		}
	}
	ssl->s_stdin = read_file(0);
}
